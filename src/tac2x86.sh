./pico -o ../tac2x6/out $1
cd ../tac2x6
python tac2x86.py out
as output.s -o output.o
ld -dynamic-linker /lib/ld-linux.so.2 -o ../src/$2 -lc output.o
rm out output.s output.o
cd ../src
