namespace Yb\Data;

class RateLimiter extends DataAbstract
{
    public function pass(string item, long seconds, long times) -> boolean
    {
        return this->backend->passRateLimiter(this->identifier, item, seconds, times);
    }

}
