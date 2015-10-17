@echo off

taskkill /f /im php-cgi.exe
copy /y build\php_yb.dll e:\php\ext\
php --ri yb
