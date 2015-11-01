namespace Yb\RateLimiter;

interface RateLimiterInterface
{
    public function passRateLimiter(string item, long seconds, long times) -> boolean;

}
