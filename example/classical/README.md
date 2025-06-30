# Example - classical
We look up the conventional way to accomplish hot-reloading.

Apparently we have to perform the following modifications project wide:
* Move our function definitions to new compile units which will become shared libraries.
* Append a function pointer for each moved function definition.
* Monitor for changes and reassign every function pointer accordingly.

Our core project has been modified accordingly.

Now, if I run `main.out`, change `hot.c` and call `make so`,
I can instantly see the changes.

The behaviour is great, but I think we can agree: the code looks aweful,
almost satanic.

For every function I introduce, I MUST write boilerplate.
Its not even the self-documenting boilerplate that is familiar to all C developers,
and even that is required only *some* of the time.

I am a programmer, laziness is my virtue; this just won't do.
