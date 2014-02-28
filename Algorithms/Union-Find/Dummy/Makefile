
LIB_SRC=dummy.cpp ../include/private/uf.cpp
LIB_HEADER=dummy.h
FOLDER=$(shell basename $(shell pwd))

DEFINES=-DLIB_HEADER=\"../../$(FOLDER)/$(LIB_HEADER)\"
INCLUDES=-I../include

ifeq ($(debug),y)
	DEBUG=-g
else
	DEBUG=-O2
endif

FLAGS=$(DEBUG) -Wall -fvisibility=hidden -shared -fPIC

all: lib

lib:
	g++ $(FLAGS) $(INCLUDES) $(DEFINES) $(LIB_SRC) -o libuf.so

clean:
	rm -f *.o *.so

