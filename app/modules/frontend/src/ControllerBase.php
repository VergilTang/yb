<?php
namespace YbApp\Modules\Frontend;

use Yb\Application;

abstract class ControllerBase
{
    protected $app;

    public function appSetup(Application $app)
    {
        $this->app = $app;
    }

    public function appInitView()
    {
        $appContext = $this->app->context;
        $appContext->viewData = (object) [];
    }

    public function appRouteRequest()
    {
        $appContext = $this->app->context;

        $appContext->requestId = 'index/index';
        $appContext->controller = 'index';
        $appContext->action = 'index';
        $appContext->params = [];
    }

    public function appStartSession()
    {
        session_save_path($this->app->config->get('core.sessionSavePath', '/tmp'));
        session_start();

        $appContext = $this->app->context;

        if (isset($_SESSION['loginMemberId'])) {
            $appContext->loginMemberId = (int) $_SESSION['loginMemberId'];
        } else {
            $appContext->loginMemberId = 0;
        }
    }

    public function appCheckPermission()
    {
        // loginMemberId & requestId
    }

    /**
     * @various
     */
    public function xxAction()
    {
        // filter inputs: query & post & uploads
        // call BLs
    }

    public function appRenderTemplate()
    {
        //
    }

}
