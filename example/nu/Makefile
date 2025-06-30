host: patch main.c
	gcc -o main-host.out main-host.c -std=c23

patch: stub.cocci
	spatch --sp-file stub.cocci main.c -o main-host.c --debug

so: main.c
	gcc -fPIC -shared -o libmain-module.so.swp main.c -std=c23 -ggdb
	mv libmain-module.so.swp libmain-module.so

clean:
	-rm main-host.c
	-rm *.out
	-rm *.so
