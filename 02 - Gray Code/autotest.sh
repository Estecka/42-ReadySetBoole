#!/bin/bash

make all \
&& ./gray_code.out 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 \
&& ./gray_code.out -1 -2 -3 -4 -5 -6 -7 -8 \
&& ./gray_code.out $RANDOM $RANDOM $RANDOM $RANDOM \
;
