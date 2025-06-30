# NOTE: you might want to invest in a Makefile module

CFLAGS= -std=c23 -ggdb

main:
	gcc ${CFLAGS} -o main.out main.c

host:
	cp -r ./ host-tree
	hot-reload.sh host-tree/main.c
	gcc ${CFLAGS} -o main-host.out main-host.c

module:
	gcc ${CFLAGS} -fPIC -shared -o libmain-host.c.so.swp main.c
	mv libmain-host.c.so.swp libmain-host.c.so

clean:
	-rm *-host.c
	-rm *.out
	-rm *.so
