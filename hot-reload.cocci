/* This script attempts to generate as little concrete code as possible.
 *  Everything that can be is outsourced to macros.
 */

@ reloader @
identifier R;
@@

R ( ... ) {
    <+...
-   RELOAD_PLACEHOLDER;
    ...+>
}

@ stub @
/* Responsible for collecting function definitions
 *  and converting them to function pointers.
 */
type T;
parameter list ps;
identifier F != {
    main,
    hot_init_,
    hot_deinit,
    has_changed,
    reloader.R
};
fresh identifier F_fn = F ## "_fn";
@@

-T F ( ps ) { ... }
+T ( * F_fn )( ps );

@ indirect_call @
identifier stub.F;
identifier stub.F_fn;
@@

-F()
+F_fn()

@ reopen @
identifier reloader.R;
@@

R ( ... ) {
+   REOPEN;
    ...
}

@ reload @
identifier reloader.R;
identifier stub.F;
identifier stub.F_fn;
@@

R ( ... ) {
    ...
++  RELOAD(F_fn, F);
}
