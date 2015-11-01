namespace Yb\Sequence;

use Yb\Db\PdoMysql;

class DbPdoMysql implements SequenceInterface
{
    const DEFAULT_TABLE = "sequence";

    protected mysql;
    protected table;

    public static function tableCreationQuery(string table) -> string
    {
        return "create table " . table . " (
                name varchar(100) not null,
                sequence int not null auto_increment,
                primary key (name),
                key (name, sequence)
            ) engine=myisam;";
    }

    public function __construct(<PdoMysql> mysql, string table = self::DEFAULT_TABLE) -> void
    {
        let this->mysql = mysql;
        let this->table = table;
    }

    public function getNextSequence(string name) -> long
    {
        return (long) this->mysql->insert(this->table, [
            "name": name
        ], "sequence", true);
    }

    public function restoreSequences(array sequences) -> void
    {
        var name, sequence;

        for name, sequence in sequences {
            this->mysql->replace([
                "name": name,
                "sequence": sequence
            ], "name");
        }
    }

}
