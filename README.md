# Ondago
> Reload while sprinting.

Non-intrusive C/C++ hot-reloading toolchain.

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
