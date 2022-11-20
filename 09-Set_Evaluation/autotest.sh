#!/bin/bash

make all \
&& echo -e "\n\t# BASE EXPRESSIONS" \
&& ./eval_set.out "A"   "0,1" "1,2" \
&& ./eval_set.out "B!"  "1" "2,3" "4,5"\
&& ./eval_set.out "AB&" "7,6,5" "6,5,4" \
&& ./eval_set.out "DE|" '1' '' "3,4,5" "5,6,7" \
&& ./eval_set.out "BC^" '' "1,2" "2,3" \
&& ./eval_set.out "DE=" '' '' "3,4" "5,6" \
&& ./eval_set.out "AC>" "6,7,8" '9' "8,9,10" \
;