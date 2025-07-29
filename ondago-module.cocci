// XXX: im repeating myself a lot because conjunction explodes;
//       i shall email them again about this
@ remove_inline_def @
type T;
identifier F;
parameter list ps;
@@

-inline
T F( ps ) { ... }

@ remove_inline_decl @
type T;
identifier F;
parameter list ps;
@@

-inline
T F( ps );

@ remove_static_def @
type T;
identifier F;
parameter list ps;
@@

-static
T F( ps ) { ... }

@ remove_static_decl @
type T;
identifier F;
parameter list ps;
@@

-static
T F( ps );
