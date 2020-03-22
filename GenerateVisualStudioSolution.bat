@echo off
pushd %~dp0\..\
call Utilities\Premake\premake5.exe vs2019
popd
PAUSE