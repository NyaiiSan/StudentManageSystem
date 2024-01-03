@echo off

gcc -I include -o build/StudManageSys.exe *.c

if errorlevel 1 goto End

start build/StudManageSys.exe

:End