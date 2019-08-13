c = gcc
options = -I include/

all: cp.o gen.o mv.o rm.o
	mkdir -p builds
	$(c) -o builds/cp cp.o gen.o
	$(c) -o builds/mv mv.o gen.o
	$(c) -o builds/rm rm.o
cp.o: src/cp.c
	$(c) $(options) -c src/cp.c
mv.o: src/mv.c
	$(c) $(options) -c src/mv.c
gen.o: src/gen.c
	$(c) $(options) -c src/gen.c
rm.o: src/rm.c
	$(c) $(options) -c src/rm.c
clean:
	rm -vR builds/
	rm *.o