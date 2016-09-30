all:
	g++ -g -shared -Iinclude -fPIC -std=c++1y src/fast_print.cpp -o libfast_print.so

test: all
	g++ -g -L. -std=c++1y -Iinclude -o test test.cpp -lfast_print
	LD_LIBRARY_PATH=$(PWD) ./test

clean:
	rm -f *.so test src/*.o
