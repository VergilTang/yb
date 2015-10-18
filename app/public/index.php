<?php
if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}
header('Content-type: text/plain; charset=UTF-8');

try {
    //

    echo \yb\std::bytesToSize(102500), PHP_EOL;

    $s = \Yb\Std::pascalCase($_SERVER['REQUEST_URI']);
    echo $s, PHP_EOL;
    echo \Yb\Std::normalCase($s), PHP_EOL;

    $s = \Yb\Std::camelCase($_SERVER['REQUEST_URI']);
    echo $s, PHP_EOL;
    echo \Yb\Std::normalCase($s), PHP_EOL;

    echo \Yb\Std::normalCase($_SERVER['REQUEST_URI']), PHP_EOL;

} catch (Exception $ex) {
    echo $ex, PHP_EOL;

}

echo sprintf(
    '%0.3fs %0.3fM',
    microtime(true) - $_SERVER['REQUEST_TIME_FLOAT'],
    memory_get_peak_usage() / (1 << 20)
), PHP_EOL;
print_R(get_included_files());
