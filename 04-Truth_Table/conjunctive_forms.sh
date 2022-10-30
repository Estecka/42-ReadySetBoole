#!/bin/bash

make all \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB&C&' 'CAB&&' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB&CD&&' 'ABCD&&&' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'ABC&|' 'AB|AC|&' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB&CD&|' 'AC|AD|BC|BD|&&&'\
;
