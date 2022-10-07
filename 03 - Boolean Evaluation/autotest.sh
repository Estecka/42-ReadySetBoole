#!/bin/bash

make all \
&& ./eval_formula.out "1" "0" "0!" "1!" "00&" "10&" "11&" "00|" "01|" "11|" "00^" "01^" "11^" \
&& ./eval_formula.out "10|!1&!" "11|0&" "101|!&" "101|&" \
&& ./eval_formula.out "0!0&00!^!1&!|" \
&& ./eval_formula.out "01|&" "0!&" "001|" \
;