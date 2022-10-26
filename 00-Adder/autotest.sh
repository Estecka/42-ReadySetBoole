#!/bin/bash

make all \
&& ./adder.out 0 1 2 3 4 5 \
&& ./adder.out -1 +1 -1 -5 +21 -125 +341\
&& ./adder.out 1 3 7 15 31 63 127 255 \
&& ./adder.out 1 5 21 125 341 \
&& ./adder.out 1 9 73 585 4681 \
&& ./adder.out 0 3 27 219 3510 \
&& ./adder.out $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM \
;
