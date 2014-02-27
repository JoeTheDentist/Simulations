
all: build_test build_perf

build_test:
	g++ -I../include test.cpp -L../Quick-Union -luf -o test

build_perf:
	g++ -I../include perf.cpp -L../Quick-Union -luf -lncurses -o perf

build_perf_p: 
	g++ -I../include perf.cpp -L../Quick-Union -luf -lncurses -DPAINT -o perf

test: build_test
	LD_LIBRARY_PATH=../Quick-Union ./test

perf: build_perf
	LD_LIBRARY_PATH=../Quick-Union ./perf

clean:
	rm -f *.o test perf

