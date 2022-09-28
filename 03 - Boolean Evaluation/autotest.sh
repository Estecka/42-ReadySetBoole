#!/bin/bash

make all \
&& ./eval_formula.out "00&" "10&" "11&" "00|" "01|" "11|" "00^" "01^" "11^" \
&& ./eval_formula.out "10|1&" "11|0&" "101|&" "101|&" \
&& ./eval_formula.out "00&00^1&|" \
&& ./eval_formula.out "01|&" "001|" \
;