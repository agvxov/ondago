#!/bin/sh

usage() {
    echo "$0 <verb> <file>+  : prepare the given files to be compiled as a hot-reloading host"
    echo "NOTE: $0 modifies the files in place!!!"
}

if [ $# -lt 2 ]; then
    usage
    exit 1
fi

VERB="$1"; shift
case "$VERB" in
    host)
        COCCI_SCRIPT=/home/anon/Swap/hot-reloading/ondago-host.cocci
        ;;
    module)
        COCCI_SCRIPT=/home/anon/Swap/hot-reloading/ondago-module.cocci
        ;;
    *)
        echo "Unknown verb."; exit 2
        ;;
esac

# --recursive-includes ?
SPATCH_FLAGS="--local-includes --include-headers --in-place --debug"

while [ $# -gt 0 ]; do
    INPUT=$1; shift
    spatch $SPATCH_FLAGS --cocci-file "$COCCI_SCRIPT" "$INPUT"
done
