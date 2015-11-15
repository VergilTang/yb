<?php
namespace YbApp\Frontend;

abstract class ControllerBase
{
    protected $app;

    public function __construct($app)
    {
        $this->app = $app;
    }

}
