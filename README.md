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
| Tool              | Description |
| :---------------: | :---------: |
| hot-reaload.cocci | Main metaprogramming script. |
| hot-reaload.sh    | Wrapper script around Coccinelle/hot-reaload.cocci |
| hot-reload.h      | C/C++ header for the reload logic. |
