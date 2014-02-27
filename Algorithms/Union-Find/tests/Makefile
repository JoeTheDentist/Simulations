
DEP_F=../Quick-Union

all: build_test build_perf

build_test: dep
	g++ -I../include test.cpp -L$(DEP_F) -luf -o test

build_perf: dep
	g++ -I../include -Wall perf.cpp -L$(DEP_F) -luf -o perf

build_perf_p: dep
	g++ -I../include perf.cpp -L$(DEP_F) -luf -lncurses -DPAINT -o perf

dep: $(DEP_F)/libuf.so

$(DEP_F)/libuf.so:
	$(MAKE) -C $(DEP_F)

test: build_test
	LD_LIBRARY_PATH=$(DEP_F) ./test

perf: build_perf
	LD_LIBRARY_PATH=$(DEP_F) ./perf

perf_p: build_perf_p
	LD_LIBRARY_PATH=$(DEP_F) ./perf

clean:
	rm -f *.o test perf

full_clean: clean
	$(MAKE) -C $(DEP_F) clean

