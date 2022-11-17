#!/bin/bash

make all \
&& ./powerset.out \
&& ./powerset.out 1 \
&& ./powerset.out 0 1 \
&& ./powerset.out 2 3 5 \
&& ./powerset.out 0 1 2 3 \
&& ./powerset.out 1 3 5 6 99 \
;
