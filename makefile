c = gcc
options = -I include/

all: gen.o cp.o mv.o rm.o ls.o
	mkdir -p builds
	$(c) -o builds/cp cp.o gen.o
	$(c) -o builds/mv mv.o gen.o
	$(c) -o builds/rm rm.o gen.o
	$(c) -o builds/ls ls.o gen.o
cp.o: src/cp.c
	$(c) $(options) -c src/cp.c
mv.o: src/mv.c
	$(c) $(options) -c src/mv.c
gen.o: src/gen.c
	$(c) $(options) -c src/gen.c
rm.o: src/rm.c
	$(c) $(options) -c src/rm.c
ls.o: src/ls.c
	$(c) $(options) -c src/ls.c
clean:
	rm -vR builds/
	rm *.o