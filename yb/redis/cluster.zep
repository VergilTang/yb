namespace Yb\Redis;

use Yb\Std;
use Yb\DataCacher\DataCacherInterface;

class Cluster implements RedisClientInterface
{
    protected slotsCacher;
    protected options;
    protected slots;
    protected connections;

    public function __construct(<DataCacherInterface> slotsCacher, array options = []) -> void
    {
        var slots;
        string host;
        long port;

        let this->slotsCacher = slotsCacher;
        let this->options = options;

        let slots = slotsCacher->fetchData();
        if slots {
            if unlikely typeof slots != "array" {
                throw new Exception("Invalid slots from cacher");
            }
            let this->slots = slots;
        } else {
            let host = (string) Std::valueAt(options, "host", Connection::DEFAULT_HOST);
            let port = (long) Std::valueAt(options, "port", Connection::DEFAULT_PORT);
            this->refleshSlots(host, port);
        }
    }

    public function runCommandByKey(string key, array cmd)
    {
        int slot;
        var result;

        let slot = yb_redis_cluster_hash_slot(key);
        let result = this->getConnectionBySlot(slot)->runCommand(cmd);

        if typeof result != "object" || ! (result instanceof Error) {
            return result;
        }

        if result instanceof ErrorMoved {
            return this->onMoved(result, cmd);
        }

        if result instanceof ErrorAsk {
            return this->onAsk(result, cmd);
        }

        throw new Exception(result->error);
    }

    public function runCommandsByKey(string key, array cmds, var resultProcessor = null) -> void
    {
        this->runCommandsByKeyInternally(key, cmds, resultProcessor, false);
    }

    protected function runCommandsByKeyInternally(string key, array cmds, var resultProcessor, bool twice) -> void
    {
        int slot;
        var results, index, result;
        bool hasResultProcessor = false, found = false;

        if resultProcessor {
            if unlikely ! is_callable(resultProcessor) {
                throw new Exception("Invalid result processor");
            }
            let hasResultProcessor = true;
        }

        let slot = yb_redis_cluster_hash_slot(key);
        let results = this->getConnectionBySlot(slot)->runCommands(cmds);

        for index, result in results {
            if typeof result != "object" || ! (result instanceof Error) {
                if hasResultProcessor {
                    {resultProcessor}(result, index);
                }
                let found = true;
                continue;
            }

            if result instanceof ErrorMoved {
                if unlikely found {
                    throw new Exception("Commands are not in one slot");
                }
                if unlikely twice {
                    throw new Exception(result->error);
                }
                this->refleshSlots(result->host, result->port);
                this->runCommandsByKeyInternally(key, cmds, resultProcessor, true);
                return;
            }

            if result instanceof ErrorAsk {
                let result = this->onAsk(result, cmds[index]);
                if hasResultProcessor {
                    {resultProcessor}(result, index);
                }
                let found = true;
                continue;
            }

            throw new Exception(result->error);
        }
    }

    protected function getConnectionBySlot(long slot) -> <Connection>
    {
        var s;

        if typeof this->slots == "array" {
            for s in this->slots {
                if slot >= s[0] && slot <= s[1] {
                    return this->getConnection(s[2][0], s[2][1]);
                }
            }
        }

        throw new Exception(sprintf("Cannot find connection for slot: %d", slot));
    }

    protected function getConnection(string host, long port) -> <Connection>
    {
        string address;
        var connection;

        let address = (string) sprintf("%s:%d", host, port);
        if fetch connection, this->connections[address] {
            return connection;
        }

        let connection = this->newConnection(host, port);
        let this->connections[address] = connection;

        return connection;
    }

    protected function newConnection(string host, long port) -> <Connection>
    {
        var options;

        let options = this->options;
        let options["host"] = host;
        let options["port"] = port;

        return new Connection(options);
    }

    protected function refleshSlots(string host, long port) -> void
    {
        var slots;

        let slots = this->getConnection(host, port)->runCommand(["CLUSTER", "SLOTS"]);
        let this->slots = slots;
        this->slotsCacher->storeData(slots);
    }

    protected function onMoved(<ErrorMoved> error, array cmd)
    {
        var result;

        this->refleshSlots(error->host, error->port);
        let result = this->getConnection(error->host, error->port)->runCommand(cmd);

        if unlikely typeof result == "object" && (result instanceof Error) {
            throw new Exception(result->error);
        }

        return result;
    }

    protected function onAsk(<ErrorAsk> error, array cmd)
    {
        var results, result;

        let results = this->getConnection(error->host, error->port)->runCommands([
            ["ASKING"],
            cmd
        ]);

        // @todo validate asking result

        if unlikely ! fetch result, results[1] {
            throw new Exception("Invalid result when asking");
        }

        if unlikely typeof result == "object" && (result instanceof Error) {
            throw new Exception(result->error);
        }

        return result;
    }

}