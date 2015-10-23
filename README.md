# Yb

Yb Framework

## Windows Build

C:\Program Files (x86)\Microsoft Visual Studio 11.0\z.bat
```
@echo off
cd \phpsdk &&^
bin\phpsdk_setvars.bat &&^
cd php55\vc11\x86\php-5.5.30 &&^
cls
```
C:\phpsdk\php55\vc11\x86\php-5.5.30\z.bat
```
@echo off
rd /s /q Release\pecl\yb
del /s /q Release\php_yb.*
svn up ..\pecl\yb &&^
buildconf --force &&^
configure --disable-all --enable-cli --enable-pdo --enable-yb=shared --disable-zts &&^
nmake &&^
upx Release\php_yb.dll &&^
copy /y Release\php_yb.dll f:\yb\build\ &&^
echo.
```

## Apache配置

httpd-vhosts.conf

```
<VirtualHost *:80>
    DocumentRoot "f:/yb/app/public"
    ServerName yb.dev
    ServerAlias *.yb.dev
    ErrorLog "logs/yb-error.log"
    CustomLog "logs/yb-access.log" common
</VirtualHost>
```

.htaccess

```
RewriteEngine On
RewriteCond %{REQUEST_FILENAME} !-f
RewriteRule .* index.php
```

## Nginx配置

```
server {
    listen      80;
    server_name .yb.s1;
    root        /home/www/yb/app/public;
    location / {
        index       index.html index.php;
        try_files   $uri $uri/ /index.php$is_args$args =404;
    }
    location ~\.php$ {
        fastcgi_pass    127.0.0.1:9000;
        fastcgi_index   index.php;
        fastcgi_param   SCRIPT_FILENAME $document_root$fastcgi_script_name;
        include         fastcgi_params;
    }
}
```

## Git Hook

nginx

```
server {
    listen      80;
    server_name ~(^|\.)(?<br>\w+)\.yb\.s1$;
    root        /home/www/yb/$br/app/public;
    location / {
        index       index.html index.php;
        try_files   $uri $uri/ /index.php$is_arg$args =404;
    }
    location ~\.php$ {
        fastcgi_pass    127.0.0.1:9000;
        fastcgi_index   index.php;
        fastcgi_param   SCRIPT_FILENAME $document_root$fastcgi_script_name;
        include         fastcgi_params;
    }
}

server {
    listen      80;
    server_name git-hook.yb.s1;
    root        /home/www/yb-git-hook;
    location / {
        index   index.html index.php;
    }
    location ~ \.php$ {
        fastcgi_pass    127.0.0.1:9000;
        fastcgi_index   index.php;
        fastcgi_param   SCRIPT_FILENAME $document_root$fastcgi_script_name;
        include         fastcgi_params;
    }
}
```

git-hook/index.php

```
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
```
