#!/bin/bash

make all \
&& echo -e '----\n' && ./truth_table.out 'A!!' 'A' \
&& echo -e '----\n' && ./truth_table.out 'AB&!' 'A!B!|' \
&& echo -e '----\n' && ./truth_table.out 'AB|!' 'A!B!&' \
&& echo -e '----\n' && ./truth_table.out 'AB^!' 'AB=' \
&& echo -e '----\n' && ./truth_table.out 'AB=!' 'AB^' \
&& echo -e '----\n' && ./truth_table.out 'AB>!' 'AB!&' \
;