#!/bin/bash

make all \
&& ./space_curve.out "0,0" "0,2" "0,7" \
&& ./space_curve.out "1,0" "2,0" "4,0" "15,0" \
&& ./space_curve.out "2,3" "3,2" "6,29" \
&& ./space_curve.out "126,486" "1024,2048" "64,4963" \
&& ./space_curve.out "0,-1" "-1,0" "-1,-1" \
&& ./space_curve.out "0,-64" "-64,0" "-64,-64" \
&& ./space_curve.out "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" "$RANDOM,$RANDOM" \
;
