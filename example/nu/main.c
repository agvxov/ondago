#include <stdio.h>
#include <dlfcn.h>
#include <sys/stat.h>
#include <time.h>

#define REASSIGN_PLACEHOLDER

#define STRINGIFY(x) # x

void h(void) {
    puts("Good.");
}

void f(void) {
    puts("Good.");
}

void reload(void) {
    static void * handle   = NULL;
    static time_t last_mod = 0;

    const char * const libpath = "./libmain-module.so";

    struct stat st;
    stat(libpath, &st);

    if (st.st_mtime <= last_mod && handle) { return; }
    last_mod = st.st_mtime;

    if (handle) { dlclose(handle); }
    handle = dlopen(libpath, RTLD_NOW);

	REASSIGN_PLACEHOLDER;
}

signed main(void) {
    while (true) {
        reload();

        h();
        f();
    }

    return 0;
}
