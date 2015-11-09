<?php
namespace YbApp\Frontend;

abstract class ControllerBase
{
    protected $app;

    public function setApplication($app)
    {
        $this->app = $app;
    }

}
