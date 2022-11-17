#!/bin/bash

make all \
&& ./SAT.out "Z" "Y!" \
&& ./SAT.out "AA&" "AA!&" "AB&" \
&& ./SAT.out "CC|" "CC!&" "DE|" \
&& ./SAT.out "CC^" "CC!^" "DE^" \
&& ./SAT.out "CC=" "CC!=" "DE=" \
&& ./SAT.out "CC>" "CC!>" "DE>" \
&& ./SAT.out "AB|C&" "XY|Y&" "MM|K&" \
&& ./SAT.out "ZXY&|" "AXX&|" "TTR&|" \
;