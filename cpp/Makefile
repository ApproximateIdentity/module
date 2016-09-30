so = libfast_print.so
soname = -lfast_print

cxx = g++
cxxflags = -std=c++1y -g -O3 -fPIC -Wall -Wextra -Wfatal-errors -pedantic-errors
includedirs = -Iinclude
libdirs = -L.
ldflags = -shared -Wl,-soname,$(so)

srcs = $(wildcard src/*.cpp)
objs = $(patsubst %.cpp,%.o,$(srcs))

all: $(so)

$(so): $(objs)
	$(cxx) $(libdirs) $(ldflags) $(objs) -o $(so) $(libs)

%.o:%.cpp
	$(cxx) $(cxxflags) $(includedirs) -c -o $@ $<

clean:
	rm -f *.o src/*.o *.so lib/*.so test

test: all
	$(cxx) $(cxxflags) $(includedirs) $(libdirs) -o test test.cpp $(soname)
	LD_LIBRARY_PATH=$(PWD) ./test
