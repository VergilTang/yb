<?php
if (!isset($_SERVER['REQUEST_TIME_FLOAT'])) {
    $_SERVER['REQUEST_TIME_FLOAT'] = microtime(true);
}
header('Content-type: text/plain; charset=UTF-8');

try {
    //

} catch (Exception $ex) {
    echo $ex, PHP_EOL;

}

echo sprintf(
    '%0.3fs %0.3fM',
    microtime(true) - $_SERVER['REQUEST_TIME_FLOAT'],
    memory_get_peak_usage() / (1 << 20)
), PHP_EOL;
print_R(get_included_files());
