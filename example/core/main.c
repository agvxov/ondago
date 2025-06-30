// @BAKE gcc -o $*.out $@ -std=c23 -ggdb
#include <stdio.h>

void h(void) {
    puts("Good.");
}

void f(void) {
    puts("Good.");
}

signed main(void) {
    while (true) {
        h();
        f();
    }

    return 0;
}
