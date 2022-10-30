#!/bin/bash

make all \
&& echo -e "\n\t# BASE EXPRESSIONS" \
&& ./negation_normal_form.out "A" "B!" "C!!" \
&& ./negation_normal_form.out "AB&!" "AB|!" \
&& ./negation_normal_form.out "AB=!" "AB^!" "AB>!" \
&& ./negation_normal_form.out "AB=" "AB^" "AB>" \
&& echo -e "\n\t# COMPLEX EXPRESSIONS" \
&& ./negation_normal_form.out "A!CD&!=" \
&& ./negation_normal_form.out "AXY>C^&!" \
;
