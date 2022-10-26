#!/bin/bash

make all \
&& echo "	# Simple expressions" \
&& ./eval_formula.out "1" "0" "0!" "1!" \
&& ./eval_formula.out "00&" "10&" "11&" \
&& ./eval_formula.out "00|" "01|" "11|" \
&& ./eval_formula.out "00^" "01^" "11^" \
&& ./eval_formula.out "00=" "01=" "11=" \
&& ./eval_formula.out "00>" "11>" "01>" "10>"\
&& echo "	# Complex expresions" \
&& ./eval_formula.out "10^!1&!" "11|0&" "101|!>" "101|&" \
&& ./eval_formula.out "0!0>00!^!1&!|" \
&& echo "	# Invalid Expressions" \
&& ./eval_formula.out "01|&" "0!&" "001|" \
;