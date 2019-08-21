c = gcc
options = -Wall -I include/
all: ready builds/temp/gen.o builds/temp/cp.o builds/temp/mv.o builds/temp/rm.o builds/temp/ls.o
	$(c) -o builds/cp builds/temp/cp.o builds/temp/gen.o
	$(c) -o builds/mv builds/temp/mv.o builds/temp/gen.o
	$(c) -o builds/rm builds/temp/rm.o builds/temp/gen.o
	$(c) -o builds/ls builds/temp/ls.o builds/temp/gen.o
ready:
	mkdir -p builds/temp
builds/temp/cp.o: src/cp.c
	$(c) $(options) -c src/cp.c -o builds/temp/cp.o
builds/temp/mv.o: src/mv.c
	$(c) $(options) -c src/mv.c -o builds/temp/mv.o
builds/temp/gen.o: src/gen.c
	$(c) $(options) -c src/gen.c -o builds/temp/gen.o
builds/temp/rm.o: src/rm.c
	$(c) $(options) -c src/rm.c -o builds/temp/rm.o
builds/temp/ls.o: src/ls.c
	$(c) $(options) -c src/ls.c -o builds/temp/ls.o
clean:
	rm -vR builds/
redo:clean all