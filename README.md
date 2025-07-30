# Ondago
> Reload while sprinting.

Non-intrusive C/C++ hot-reloading toolchain.

## Description
Ondago will allow you to introduce hot-reloading to your project quickly and painlessly.

Non-intrusive means that the code base won't have to drastically change.
Only a few lines of code will have to be added,
which will have no effect for non-hot-reloading builds.
This is accomplished by augmenting the build system.

Ondago follows the host-module hot-reloading pattern.
The host contains the base application loop and will continuously run, preserving state.
The module is a dynamic library containing actual logic which will be repeatedly patched.

The host and the module will be procedurally generated from the project.

## Problem statement
Please read the following documents in the order they are provided.
Pay attention to the contents of their directories too.
* [example/core/README.md](example/core/README.md)
* [example/classical/README.md](example/classical/README.md)
* [example/nu/README.md](example/nu/README.md)

## Tooling
| Tool                     | Description |
| :----------------------: | :---------: |
| ondago-host.cocci        | Host metaprogramming script. Stubs everything. |
| ondago-module.cocci      | Module metaprogramming script. Removes problematic function specifiers. |
| ondago-spatch-wrapper.sh | Wrapper script around our metaprogramming scripts. |
| ondago.h                 | C/C++ header for the reload logic. |
| env.sh                   | Emulates an environment where Ondago is installed. |
