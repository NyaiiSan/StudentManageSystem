@echo off

if not exist build md build

gcc -I include -o build/StudManageSys.exe *.c

if errorlevel 1 goto End

start build/StudManageSys.exe

:End