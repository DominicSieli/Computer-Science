cd ..

mkdir Assembly

for %%I in (.) do set project=%%~nxI
set file=%project%_%~n0

g++ -S -O3 -std=c++17 Source/*.cpp -o Assembly/%file%