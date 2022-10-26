#!/bin/bash

make all \
&& ./multiplier.out 1 2 3 4 5 0 \
&& ./multiplier.out -1 +1 -1 -5 +21 -125 +341\
&& ./multiplier.out 1 3 7 15 31 63 127 255 \
&& ./multiplier.out 1 5 21 125 341 \
&& ./multiplier.out 1 9 73 585 4681 \
&& ./multiplier.out 1 3 27 219 3510 \
&& ./multiplier.out $RANDOM $RANDOM $RANDOM $RANDOM $RANDOM \
;
