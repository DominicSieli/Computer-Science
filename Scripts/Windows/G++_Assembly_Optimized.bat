cd ../..

mkdir Assembly\Windows

set projectName=Assembly_Optimized

g++ -S -O3 -std=c++17 Source/*.cpp -o Assembly/Windows/%projectName%