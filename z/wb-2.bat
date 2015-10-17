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
