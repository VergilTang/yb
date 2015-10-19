<?php
namespace YbApp\Modules\Frontend;

use Yb\Application\ApplicationFilterInterface;
use Yb\Application\Core;

class Bootstrap
{
    protected $core;

    public function filterApplication(Core $core)
    {
        $this->core = $core;
    }

}
