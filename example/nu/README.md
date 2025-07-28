# Example - nu

So, we have new requirements:
* Automate the transformation.
* Keep the project structure intact and thereby nice and tidy.

Our ideal situation is one where we compile out project twice:
1. Where everything is only declared, except for `main()` (*Host*).
2. Where everything is defined (*Module*).

The second one is easy;
the code stays as is, we only need to change the compile flags.
The first however...

We will need some kind of metaprogramming,
but CPP macros are not powerful enough
and magling existing code with external tools is extremely error prone...

Meet Coccinella.
It is a development tool from 2004 which is
extensively used in the development of the Linux kernel.
Simply put, it is a syntax aware pre(-pre-)processor.
She matches syntax tree based rules and produces guaranteed to be valid C/C++.

Without wasting more time, checkout [stub.cocci](stub.cocci).

It does just what we need.
After a minimal modification to our `Makefile`,
hot-reloading works exactly like it did before,
but our codebase has not turned into hot-vomit!

Now, the Coccinelle script will happily work on any input file we give it,
and the reload logic won't change between projects;
therefor we can abstract our work into a package.
That is what this repo is.
