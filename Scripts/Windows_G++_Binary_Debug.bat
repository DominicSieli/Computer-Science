cd ..

mkdir Binaries

for %%I in (.) do set project=%%~nxI
set file=%project%_%~n0

g++ -g -Wall -std=c++17 Source/*.cpp -o Binaries/%file%

start Binaries/%file%