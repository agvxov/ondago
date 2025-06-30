#!/bin/bash

INPUT=$1
EXT="${INPUT##*.}"
OUTPUT=$(basename "$INPUT")-host${EXT}

COCCI_SCRIPT=/home/anon/Swap/hot-reloading/hot-reload.cocci
SPATCH_FLAGS="--local-includes --include-headers --in-place"

# --recursive-includes ?
spatch ${SPATCH_FLAGS} --cocci-file $COCCI_SCRIPT $INPUT
