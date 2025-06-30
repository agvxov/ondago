# NOTE: you might want to invest in a Makefile module

CFLAGS= -std=c23 -ggdb

main:
	gcc ${CFLAGS} -o main.out main.c

host:
	-rm -frfr ../host-tree ./host-tree
	cp -r ./ ../host-tree
	mv ../host-tree .
	hot-reload.sh host-tree/main.c
	cd host-tree/; \
	gcc ${CFLAGS} -o ../main-host.out main.c

module:
	gcc ${CFLAGS} -fPIC -shared -o libmain.c.so.swp main.c
	mv libmain.c.so.swp libmain.c.so

hot: clean host module

clean:
	-rm -frfr ../host-tree ./host-tree
	-rm *-host.c
	-rm *.out
	-rm *.so
