@ stub @
// Transform definitions to corresponding function pointers.
type T;
parameter list ps;
identifier F != { main, reload };
fresh identifier F_fn = F ## "_fn";
@@

-T F ( ps ) { ... }
+T ( * F_fn )( ps );

@ indirect_call @
// Convert the calls to use our function pointers.
identifier stub.F;
identifier stub.F_fn;
@@

-F ()
+F_fn ()

@ reassign @
// Automate reassigning our function pointers.
// NOTE: At the time of writting this,
//        the placeholder trick is the easiest method of appending I am aware of.
//       I am sure there is a cleaner alternative.
identifier R = reload;
identifier stub.F;
identifier stub.F_fn;
@@

R ( ... ) {
	...
-	REASSIGN_PLACEHOLDER;
++  F_fn = dlsym(handle, STRINGIFY( F ));
}
