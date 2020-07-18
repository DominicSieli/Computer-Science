cd ..

mkdir Binaries

@echo off
echo #pragma once > Source\Configuration.h
echo #define WINDOWS >> Source\Configuration.h
echo #define DEBUG >> Source\Configuration.h

for %%I in (.) do set project=%%~nxI
set file=%project%_%~n0

g++ -g -Wall -std=c++17 Source/*.cpp -o Binaries/%file%

start Binaries/%file%