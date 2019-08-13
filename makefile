all: cp.o gen.o mv.o
	mkdir -p builds
	gcc -o builds/cp cp.o gen.o
	gcc -o builds/mv mv.o gen.o
cp.o: cp.c
	gcc -c cp.c
mv.o: mv.c
	gcc -c mv.c
gen.o: gen.c
	gcc -c gen.c
clean:
	rm -vR builds/
	rm *.o