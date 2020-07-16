cd ..

mkdir Binaries

for %%I in (.) do set project=%%~nxI
set file=%project%_%~n0

g++ -O3 -std=c++17 Source/*.cpp -o Binaries/%file%

start Binaries/%file%