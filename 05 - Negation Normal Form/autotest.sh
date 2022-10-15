#!/bin/bash

make all \
&& ./negation_normal_form.out "A" "!A" \
&& ./negation_normal_form.out "AB&!" "AB|!" "AB^!" "AB=!" "AB>!" \
;
