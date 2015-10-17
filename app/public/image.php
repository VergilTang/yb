<?php

header('content-type: image/png');


$len = mt_rand(4, 6);
$text = \Nc\Std::randString($len);

$w = mt_rand(400, 800);
$h = mt_rand(200, 400);

header('Content-type: image/png');

echo (new \Yb\Image\Gd([
    'font' => 'msyh.ttc',
]))->captcha($text, $w, $h);
