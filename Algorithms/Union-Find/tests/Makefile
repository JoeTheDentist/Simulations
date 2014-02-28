
# Make usage
# For all:
#     debug=[y,N]             prepare the build in debug mode, useful for investigation
#     module=[../Quick-Union] path to the module that contain libuf.so and its Makefile for the simulation
#
# For perf:
#     callgrind=[y,N]         prepare the build for callgrind (requires valgrind headers)
#     paint=[y,N]             prepare the build for visual check (requires lncurses library)
#     box=[20]                N positive number, size of the simulated boxes (N x N)
#     sample=[100]            N positive number, number of samples to run
#     sleep=[100000]          N positive number, time to sleep (micro second) between two screen refresh
#
# Example: make perf box=10 sample=1 sleep=1000000 paint=y (sleep 1s, between each draw, for a 10x10 box, for a single run).
#
# For test:
#     gtest=[Y,n] use google c++ test framework (requires gtest installed).
#
# Example: make test gtest=n (run the tests, without gtest).

ifeq ($(callgrind),y)
	DPERF=-DPERF
endif
ifeq ($(paint),y)
	DPAINT=-DPAINT -lncurses
endif
ifeq ($(debug),y)
	DEBUG=-g
else
	DEBUG=-O2
endif
ifdef box
	BOX_DEF=BOX=$(box)
else
	BOX_DEF=BOX=20
endif
ifdef sample
	SAMPLE_DEF=SAMPLE=$(sample)
else
	SAMPLE_DEF=SAMPLE=100
endif
ifdef sleep
	SLEEP_DEF=SLEEP=$(sleep)
else
	SLEEP_DEF=SLEEP=100000
endif
ifdef module
	DEP_F=$(module)
else
	DEP_F=../Quick-Union
endif
ifneq ($(gtest),n)
        GTEST=-DGTEST -lgtest -pthread
endif

all: build_test build_perf

build_test: dep
	g++ -I../include test.cpp -L$(DEP_F) $(DEBUG) $(GTEST) -luf -o test

build_perf: dep
	g++ -I../include -Wall perf.cpp -L$(DEP_F) $(DPERF) $(DPAINT) $(DEBUG) -D$(BOX_DEF) -D$(SAMPLE_DEF) -D$(SLEEP_DEF) -luf -o perf

dep: $(DEP_F)/libuf.so

$(DEP_F)/libuf.so:
	$(MAKE) -C $(DEP_F)

test: build_test
	LD_LIBRARY_PATH=$(DEP_F) ./test

perf: build_perf
	LD_LIBRARY_PATH=$(DEP_F) ./perf

cg:
	LD_LIBRARY_PATH=$(DEP_F) valgrind --tool=callgrind --collect-atstart=no ./perf

clean:
	rm -f *.o callgrind.out.* test perf

cleaaan: clean
	$(MAKE) -C $(DEP_F) clean

