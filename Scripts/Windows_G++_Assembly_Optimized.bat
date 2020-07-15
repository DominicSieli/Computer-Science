cd ..

mkdir Assembly

set file=Windows_G++_Assembly_Optimized

g++ -S -O3 -std=c++17 Source/*.cpp -o Assembly/%file%