#ifndef HOTRELOAD_H
#define HOTRELOAD_H

/* User overwritable dl error reporting.
 * The parameter will usually be a call to dlerror().
 */
#ifndef ECHO_DL_ERROR
#define ECHO_DL_ERROR(x) \
    fprintf(stderr, "hot-reload error: %s\n", x)
#endif

// NOTE: thos is a copy of nargs.h
#ifndef NARGS_H
#define NARGS_H
    #define NARG(...) \
             PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
    #define PP_NARG_(...) \
             PP_128TH_ARG(__VA_ARGS__)
    #define PP_128TH_ARG( \
              _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
             _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
             _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
             _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
             _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
             _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
             _61,_62,_63,_64,_65,_66,_67,_68,_69,_70, \
             _71,_72,_73,_74,_75,_76,_77,_78,_79,_80, \
             _81,_82,_83,_84,_85,_86,_87,_88,_89,_90, \
             _91,_92,_93,_94,_95,_96,_97,_98,_99,_100, \
             _101,_102,_103,_104,_105,_106,_107,_108,_109,_110, \
             _111,_112,_113,_114,_115,_116,_117,_118,_119,_120, \
             _121,_122,_123,_124,_125,_126,_127,N,...) N
    #define PP_RSEQ_N() \
             127,126,125,124,123,122,121,120, \
             119,118,117,116,115,114,113,112,111,110, \
             109,108,107,106,105,104,103,102,101,100, \
             99,98,97,96,95,94,93,92,91,90, \
             89,88,87,86,85,84,83,82,81,80, \
             79,78,77,76,75,74,73,72,71,70, \
             69,68,67,66,65,64,63,62,61,60, \
             59,58,57,56,55,54,53,52,51,50, \
             49,48,47,46,45,44,43,42,41,40, \
             39,38,37,36,35,34,33,32,31,30, \
             29,28,27,26,25,24,23,22,21,20, \
             19,18,17,16,15,14,13,12,11,10, \
             9,8,7,6,5,4,3,2,1,0
#endif

#include <stdlib.h>
#include <stdarg.h>
#include <time.h>
#include <dlfcn.h>
#include <sys/stat.h>

/* The .so name that will be mangled from a compile unit.
 *  To keep things simple, we keep the original extension
 *   and respect that choice throughout the tooling.
 */
#define SO_NAME(x) \
    "./" "lib" x ".so"

/* Defines a file to be monitored for changes.
 * This shall be your .so file(s).
 * You should leave `prerequisites` alone.
 * It is malloc()'d.
 * It is a null object terminated array, where .name == NULL is a null object.
 */
struct prerequisite {
    const char * name;
    time_t touchstamp;
} * prerequisites;

#define hot_init(...) hot_init_(NARG(__VA_ARGS__), __VA_ARGS__)
void hot_init_(int n, ...) {
    va_list va;
    va_start(va);

    prerequisites = malloc(sizeof(struct prerequisite) * (n+1));

    for (int i = 0; i < n; i++) {
        const char * name = va_arg(va, const char *);
        prerequisites[i] = (struct prerequisite) {
            .name       = name,
            .touchstamp = 0,
        };
    }
    
    prerequisites[n] = (struct prerequisite) {
        .name       = NULL,
        .touchstamp = 0,
    };

    va_end(va);
}

void hot_deinit(void) {
    free(prerequisites);
}

// --- These macros are used for generting the body of reload()

/* We need to generate string literals to be used in dlsym() calls.
 * Coccinelle is either incapable of generating parameterised string literals,
 *  or I'm simply bad with her.
 * Regardless this is perfectly fine, because we got the preprocessor.
 */
#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

// early return logic
#define REOPEN \
    static void * handle = NULL; \
    \
    if (handle && !has_changed()) { return; } \
    \
    if (handle) { dlclose(handle); } \
    handle = dlopen(SO_NAME(__FILE__), RTLD_NOW); \
    if (!handle) { ECHO_DL_ERROR(dlerror()); } \

/* Check for updates; bump all touchstamps.
 */
bool has_changed(void) {
    int r = false;

    for (
      struct prerequisite * p = prerequisites;
      p->name;
      p++
    ) {
        struct stat sb;
        stat(p->name, &sb);
        if (sb.st_mtime > p->touchstamp) {
            r = true;
            p->touchstamp = sb.st_mtime;
        }
    }

    return r;
}

#define RELOAD(F_fn, F) do { \
    F_fn = dlsym(handle, STRINGIFY(F)); \
    if (!F_fn) { ECHO_DL_ERROR(dlerror()); } \
} while (0)

#define RELOAD_PLACEHOLDER

#endif
