#include <stdio.h>
#include "h.h"

#include "hot-reload.h"

void f(void) {
    puts("Good.");
}

void g(void) {
    puts("Good.");
}

void hot_rebind(void) {
    RELOAD_PLACEHOLDER;
}

signed main(void) {
    while (true) {
        h();
        f();
        g();
    }

    return 0;
}
