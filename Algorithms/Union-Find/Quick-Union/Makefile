
LIB_SRC=qu.cpp

all: lib

lib:
	g++ -shared -fPIC -I../include -Wall $(LIB_SRC) -o libuf.so

lib_dbg:
	g++ -shared -g -fPIC -I../include -Wall -DDEBUG $(LIB_SRC) -o libuf.so

clean:
	rm -f *.o *.so

