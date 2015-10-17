<?php
define('SECRET', '');
$validBranches = [
    'refs/heads/master' => 'master',
];

header('Content-type: text/plain; charset=utf-8');
$input = @json_decode(file_get_contents('php://input'), true);
if (!$input) {
    exit('Invalid input');
}
if (SECRET && (!isset($input['secret']) || $input['secret'] != SECRET)) {
    exit('Wrong secret');
}
if (!isset($validBranches[$input['ref']])) {
    exit('Invalid branche: '.$input['ref']);
}
if (!chdir('/home/www/yb/'.$validBranches[$input['ref']])) {
    exit('Cannot chdir');
}
echo `git pull`;
