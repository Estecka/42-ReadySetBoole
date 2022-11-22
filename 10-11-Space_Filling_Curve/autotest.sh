#!/bin/bash

make all \
&& ./space_curve.out "0,0" "2,3" "3,2" \
&& ./space_curve.out "126,486" "1024,2048" "64,4963" \
&& ./space_curve.out "0,-1" "-1,0" "-1,-1" \
&& ./space_curve.out "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" \
;
