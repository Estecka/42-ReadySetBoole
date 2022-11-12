#!/bin/bash

make all \
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'ABCD&&|' 'AB|AC|AD|&&' \
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'ABCD&||' 'ABC||ABD||&'\
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'ABCDE&&||' 'ABC||ABD||ABE||&&' \
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'ABCDE&|||' 'ABCD|||ABCE|||&' \
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'ABCDE&&&|' 'AB|AC|AD|AE|&&&' \
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'AB&CD&|E|' 'AC|AD|BC|BD|&&&E|' 'ACE||ADE||BCE||BDE||&&&' \
&& echo -e '\n----\n' && ./truth_table.out --compare --short 'AB&CD&EF&||' 'AB&CE|CF|DE|DF|&&&|' 'ACE||ACF||ADE||ADF||BCE||BCF||BDE||BDF||&&&&&&&' \
;
