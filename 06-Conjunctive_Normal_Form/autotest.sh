#!/bin/bash

make all \
&& echo -e "\n\t# BASE OPERATORS" \
&& ./conjunctive_normal_form.out "A" "B!" "C!!" \
&& ./conjunctive_normal_form.out "AB&"  "AB|" \
&& ./conjunctive_normal_form.out "AB&!" "AB|!" \
&& ./conjunctive_normal_form.out "AB="  "AB^"  "AB>" \
&& ./conjunctive_normal_form.out "AB=!" "AB^!" "AB>!" \
&& echo -e "\n\t# NO-OP EXPRESSIONS" \
&& ./conjunctive_normal_form.out "AB&" "ABC&&" "ABCD&&&" \
&& ./conjunctive_normal_form.out "AB|" "ABC||" "ABCD|||" \
&& ./conjunctive_normal_form.out "ABC|&" "ABCD||&" "ABCD|&&" "AB|CD&&" \
&& echo -e "\n\t# REMARKABLE EXPRESSIONS" \
&& ./conjunctive_normal_form.out "AB&C&" "AB&CD&&" "ABC&&DEF&&&" \
&& ./conjunctive_normal_form.out "ABC&|" "AB&C|" "AB&CD&|" "ABC&&DEF&&|" \
&& echo -e "\n\t# COMPLEX EXPRESSIONS" \
&& ./conjunctive_normal_form.out "ABC&&DE&FG&&&" "DA&B!C&&EN&I!!CK!||&H&&" \
&& ./conjunctive_normal_form.out "AB&C|" "AB&CD&|" "AB&CD|&" "AB&CD|&" \
&& ./conjunctive_normal_form.out "AB^C&" "AB^C&D&" "DAB^C&&" \
&& ./conjunctive_normal_form.out "ABCD&||" "ABCD|&|" \
&& ./conjunctive_normal_form.out 'A!B!|AB|&C!D!|CD|&&AB&A!B!&|CD&C!D!&|&|' \
&& ./conjunctive_normal_form.out 'ABC&|DEF&|&0|' \
;
