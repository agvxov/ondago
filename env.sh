activate() {
    local dir
    dir="$(realpath .)"

    # PATH
    export _OLD_PATH="$PATH"
    export PATH="$PATH:$dir"

    # CPATH
    export _OLD_CPATH="${CPATH:-}"
    export CPATH="${CPATH:-}:$dir"

    # PS1
    export _OLD_PS1="$PS1"
    export PS1="(env) $PS1"
}

deactivate() {
    export PATH="$_OLD_PATH"
    export CPATH="$_OLD_CPATH"
    export PS1="$_OLD_PS1"

    unset activate deactivate
    unset _OLD_PATH _OLD_CPATH _OLD_PS1
}

activate
