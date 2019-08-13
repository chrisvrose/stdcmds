all: cp.o gen.o
	gcc -o cp cp.o gen.o
cp: cp.c
	gcc -c cp.c
gen: gen.c
	gcc -c gen.c