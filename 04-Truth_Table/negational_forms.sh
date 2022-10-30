#!/bin/bash

make all \
&& echo -e '\n----\n' && ./truth_table.out --compare 'A!!' 'A' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB&!' 'A!B!|' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB|!' 'A!B!&' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB^!' 'AB&A!B!&|' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB=!' 'A!B!|AB|&' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB>!' 'AB!&' \
&& echo -e '\n----\n' && ./truth_table.out --compare 'AB>' 'A!B|' \
;
