#!/bin/bash

make all \
&& ./truth_table.out "Z" "Y!" \
&& ./truth_table.out "AA&" "AB&" \
&& ./truth_table.out "CC|" "DE|" \
&& ./truth_table.out "CC^" "DE^" \
&& ./truth_table.out "CC=" "DE=" \
&& ./truth_table.out "CC>" "DE>" \
&& ./truth_table.out "AB|C&" "XY|H&" "MM|K&" \
;