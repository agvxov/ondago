main: so
	gcc main.c -o main.out -ggdb
	
so:
	gcc -fPIC -shared hot.c -o libhot.so.swp
	mv libhot.so.swp libhot.so

clean:
	-rm *.out
	-rm *.so
