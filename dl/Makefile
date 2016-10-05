all:
	gcc -c -fPIC test.c
	gcc -shared -o libtest.so test.o
	gcc -o main main.c -ldl

clean:
	rm -f *.o *.so main
