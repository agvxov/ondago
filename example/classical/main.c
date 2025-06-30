#include <dlfcn.h>
#include <sys/stat.h>
#include <time.h>

static void (*h)(void) = NULL;
static void (*f)(void) = NULL;

void reload(void) {
    static void * handle   = NULL;
    static time_t last_mod = 0;

    const char * const libpath = "./libhot.so";

    struct stat st;
    stat(libpath, &st);

    if (st.st_mtime <= last_mod && handle) { return; }
    last_mod = st.st_mtime;

    if (handle) { dlclose(handle); }
    handle = dlopen(libpath, RTLD_NOW);

    h = dlsym(handle, "h");
    f = dlsym(handle, "f");

}

signed main(void) {
    while (true) {
        reload();

        h();
        f();
    }

    return 0;
}
