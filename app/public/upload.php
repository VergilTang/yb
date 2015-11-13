<?php

$app = new Yb\Application();

$app('uploadStorage', function($app) {
    if (Yb\Upload\Fastdfs::isSupported()) {
        $app['baseUrl'] = 'http://static.pre.ybserver.com';
        return new Yb\Upload\Fastdfs();
    }
    $app['baseUrl'] = '/upload';
    return new Yb\Upload\FileSystem(__DIR__.'/upload');
});

$app('uploader', function($app) {
    $u = new Yb\Upload\Uploader('jpg,jpeg,png,gif');
    $u->setStorage($app->uploadStorage);
    return $u;
});

session_start();

function fetchSession($name) {
    if (isset($_SESSION[$name])) {
        $r = $_SESSION[$name];
        unset($_SESSION[$name]);
        return $r;
    }
}

if (isset($_FILES['f'])) {
    try {
        $uploadedFile = $app->uploader->pick('f');
        $lastUpload = $uploadedFile->save();
        if (!$lastUpload) {
            throw new Exception('Error: %s'.var_export($uploadedFile, true));
        }
        $_SESSION['lastUpload'] = $app['baseUrl'].$lastUpload;
        header('Location: upload.php');
        exit;
    } catch (Exception $ex) {
        $_SESSION['lastError'] = (string) $ex;
    }
}

?>
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<title>Upload Test</title>
</head>
<body>
<?php if ($lastError = fetchSession('lastError')): ?>
<pre>
<?= htmlspecialchars($lastError); ?>
</pre>
<hr />
<?php endif; ?>
<?php if ($lastUpload = fetchSession('lastUpload')): ?>
<img alt="" src="<?= $lastUpload; ?>" />
<hr />
<?php endif; ?>
<form action="" method="post" enctype="multipart/form-data">
<input type="file" name="f" />
<button>Upload!</button>
</form>
</body>
</html>
