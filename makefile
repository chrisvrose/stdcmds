all: cp.o gen.o mv.o
	mkdir -p builds
	gcc -o builds/cp cp.o gen.o
	gcc -o builds/mv mv.o gen.o
cp.o: src/cp.c
	gcc -c -I include/ src/cp.c
mv.o: src/mv.c
	gcc -c -I include/ src/mv.c
gen.o: src/gen.c
	gcc -c -I include/ src/gen.c
clean:
	rm -vR builds/
	rm *.o