all:
	gcc -g -shared -Iinclude -fPIC -std=c99 src/fast_print.c -o libfast_print.so

test: all
	gcc -g -L. -std=c99 -Iinclude -o test test.c -lfast_print
	LD_LIBRARY_PATH=$(PWD) ./test

clean:
	rm -f *.so test src/*.o
