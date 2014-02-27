
LIB_SRC=qu.cpp

ifeq ($(debug),y)
	DEBUG=-g
else
	DEBUG=-O2
endif

all: lib

lib:
	g++ -shared -fPIC -I../include -Wall $(DEBUG) $(LIB_SRC) -o libuf.so

clean:
	rm -f *.o *.so

