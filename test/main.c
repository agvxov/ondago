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
    hot_init(SO_NAME(__FILE__));

    while (true) {
        hot_rebind();

        h();
        f();
        g();
    }

    return 0;
}
