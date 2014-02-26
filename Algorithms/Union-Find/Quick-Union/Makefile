
LIB_SRC=qu.cpp

all: lib

lib: lib.o
	g++ -shared lib.o -o libuf.so

lib.o:
	g++ -fPIC -I../include -Wall -c $(LIB_SRC) -o lib.o

clean:
	rm -f *.o *.so

