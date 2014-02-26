
all: build_test build_perf

build_test: test.o
	g++ -L../Quick-Union -luf test.o -o test

test.o:
	g++ -c -I../include test.cpp -o test.o

build_perf: perf.o
	g++ -L../Quick-Union -luf perf.o -o perf

perf.o:
	g++ -std=c++0x -c -I../include perf.cpp -o perf.o

test: build_test
	LD_LIBRARY_PATH=../Quick-Union ./test

perf: build_perf
	LD_LIBRARY_PATH=../Quick-Union ./perf

clean:
	rm -f *.o test perf

