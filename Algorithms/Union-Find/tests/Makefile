
EXEC=test_uf

all: build

build: main.o
	g++ -L../Quick-Union -luf main.o -o $(EXEC)

main.o:
	g++ -c -I../include main.cpp -o main.o

test: build
	LD_LIBRARY_PATH=../Quick-Union ./$(EXEC)

clean:
	rm -f *.o $(EXEC)

