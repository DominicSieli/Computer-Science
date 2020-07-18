cd ..

mkdir Binaries

echo #pragma once > Source\Configuration.h
echo #define WINDOWS >> Source\Configuration.h

for %%I in (.) do set project=%%~nxI
set file=%project%_%~n0

g++ -O3 -std=c++17 Source/*.cpp -o Binaries/%file%

start Binaries/%file%