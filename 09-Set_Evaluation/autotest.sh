#!/bin/bash

make all \
&& echo -e "\n\t# BASE EXPRESSIONS" \
&& ./eval_set.out "0"   "0,1" "1,2" "" \
&& ./eval_set.out "1"   "0,1" "1,2" "" \
&& ./eval_set.out "A"   "0,1" "1,2" \
&& ./eval_set.out "B!"  "1" "2,3" "4,5"\
&& ./eval_set.out "AB&" "7,6,5" "6,5,4" \
&& ./eval_set.out "CD|" '0,1,2' '' "5,3,4" "5,6,7" \
&& ./eval_set.out "BC^" '0' "1,2" "2,3" \
&& ./eval_set.out "CD=" '0' '' "3,4,5" "5,6" \
&& ./eval_set.out "AC>" "6,7,8" '1,9' "8,9,10" \
&& echo -e "\n\t# COMPLEX EXPRESSIONS" \
&& ./eval_set.out "AA^BB!=|!" "0,1" "2,3" \
&& ./eval_set.out "AB&CD|!^" "0,1,9" "1,2" "3,0" "0,5" \
&& ./eval_set.out "ABCDE||||" '0,5' '1,6' '2,7' '3,8' '4,9' \
;