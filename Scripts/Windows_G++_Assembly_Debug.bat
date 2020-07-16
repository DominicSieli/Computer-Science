cd ..

mkdir Assembly

for %%I in (.) do set project=%%~nxI
set file=%project%_%~n0

g++ -S -g -Wall -std=c++17 Source/*.cpp -o Assembly/%file%