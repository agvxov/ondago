# NOTE: you might want to invest in a Makefile module

CFLAGS += -std=c23 -ggdb
OUT := main.out

HOST.d   := $${TMPDIR:-/tmp}/ondago-host-tree
MODULE.d := $${TMPDIR:-/tmp}/ondago-module-tree

SOURCE := main.c z.c
SOURCE.H := $(addprefix ${HOST.d}/,${SOURCE})
SOURCE.M := $(addprefix ${MODULE.d}/,${SOURCE})

main:
	gcc ${CFLAGS} -o ${OUT} ${SOURCE}

host:
	-rm -r ${HOST.d}
	cp -r ./ ${HOST.d}/
	ondago-spatch-wrapper.sh host ${SOURCE.H}
	cd ${HOST.d}/; \
		gcc ${CFLAGS} -o ${OUT} main.c
	mv ${HOST.d}/${OUT} .

module:
	rsync -av --update ./ ${MODULE.d}/
	ondago-spatch-wrapper.sh module ${SOURCE.M}
	gcc ${CFLAGS} -fPIC -shared -o ${MODULE.d}/libmain.c.so ${SOURCE.M}
	mv ${MODULE.d}/libmain.c.so .

hot: clean host module

clean:
	-rm -r ${HOST.d} ${MODULE.d}
	-rm *.out
	-rm *.so
