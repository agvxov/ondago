# NOTE: you might want to invest in a Makefile module

HOT_INC.d := $(realpath ../)
HOT_BIN := ../hot-reload.sh

CFLAGS := -std=c23 -I${HOT_INC.d} -ggdb

main:
	gcc ${CFLAGS} -o main.out main.c z.c

host:
	-rm -frfr ../host-tree ./host-tree
	cp -r ./ ../host-tree
	mv ../host-tree .
	${HOT_BIN} host-tree/main.c
	cd host-tree/; \
	gcc ${CFLAGS} -o ../main-host.out main.c

module:
	gcc ${CFLAGS} -fPIC -shared -o libmain.c.so.swp main.c z.c
	mv libmain.c.so.swp libmain.c.so

hot: clean host module

clean:
	-rm -frfr ../host-tree ./host-tree
	-rm *-host.c
	-rm *.out
	-rm *.so
