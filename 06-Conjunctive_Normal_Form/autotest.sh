#!/bin/bash

make all \
&& echo -e "\n\t# BASE EXPRESSIONS" \
&& ./conjunctive_normal_form.out "A" "B!" "C!!" \
&& ./conjunctive_normal_form.out "AB&!" "AB|!" \
&& ./conjunctive_normal_form.out "AB=!" "AB^!" "AB>!" \
&& ./conjunctive_normal_form.out "AB=" "AB^" "AB>" \
&& echo -e "\n\t# COMPLEX EXPRESSIONS" \
&& ./conjunctive_normal_form.out "AB&C&" "AB&CD&&" \
&& ./conjunctive_normal_form.out "AB&C|" "AB&CD&|" "AB&CD|&" "AB&CD|&" \
&& echo -e "\n\t# NO-OP EXPRESSIONS" \
&& ./conjunctive_normal_form.out "AB&" "ABC&&" "ABCD&&&" \
&& ./conjunctive_normal_form.out "AB|" "ABC||" "ABCD|||" \
&& ./conjunctive_normal_form.out "ABC|&" "ABCD||&" "ABCD|&&" "AB|CD&&" \
;
