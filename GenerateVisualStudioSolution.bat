@echo off
call Utilities\Premake\premake5.exe vs2019
IF %ERRORLEVEL% NEQ 0
(
  PAUSE
)