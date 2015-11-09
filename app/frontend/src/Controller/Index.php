<?php
namespace YbApp\Frontend\Controller;

use YbApp\Frontend\ControllerBase;

class Index extends ControllerBase
{
    public function indexAction()
    {
        throw new \Exception();
    }

    public function testAction()
    {
        $this->app['viewData'] = [
            'hello' => json_encode(func_get_args()),
        ];

        // $this->app['viewData']['hello'] = 1;
    }

}
