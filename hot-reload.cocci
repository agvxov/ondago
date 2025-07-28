/* This script attempts to generate as little concrete code as possible.
 *  Everything that can be, is outsourced to macros.
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

-T F( ps ) { ... }
+T ( * F_fn )( ps );

@ point @
/* Responsible for collecting function declarations
 *  and converting them to function pointers.
 */
type T;
parameter list ps;
identifier F;
fresh identifier F_fn = F ## "_fn";
@@

-extern T F ( ps );
+T ( * F_fn )( ps );

@ indirect_call_stub @
identifier stub.F;
identifier stub.F_fn;
@@

-F()
+F_fn()

/* XXX: i am repeating myself
 *       and i dont know if its necessary
 */
@ indirect_call_point @
identifier point.F;
identifier point.F_fn;
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

@ reload_stub @
identifier reloader.R;
identifier stub.F;
identifier stub.F_fn;
@@

R ( ... ) {
    ...
++  RELOAD(F_fn, F);
}

/* XXX: again, repeating myself;
 *       the grammar supports coma seperated lists,
 *       but it seems to only respect the last element.
 *       i suspect this might be another bug.
 *       i shall emil' them.
 */
@ reload_point @
identifier reloader.R;
identifier point.F;
identifier point.F_fn;
@@

R ( ... ) {
    ...
++  RELOAD(F_fn, F);
}
