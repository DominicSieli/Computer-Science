cd ..

mkdir Binaries

set file=Windows_G++_Binary_Optimized

g++ -O3 -std=c++17 Source/*.cpp -o Binaries/%file%

start Binaries/%file%