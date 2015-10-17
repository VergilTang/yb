<?php

header('content-type: image/png');


$len = mt_rand(4, 6);
$text = \Nc\Std::randString($len);

$w = mt_rand(400, 800);
$h = mt_rand(200, 400);

header('Content-type: image/png');

if (mt_rand() % 2) {
    $im = new \Yb\Image\Gd();
} else {
    $im = new \Yb\Image\Imagick();
    $im->setDefaultOptions([
        'font' => 'c:/windows/fonts/msyh.ttc',
    ]);
}

echo $im->captcha($text, $w, $h)->drawTo(
    $im->watermark(get_class($im)),
    $im::RIGHT_BOTTOM
);
