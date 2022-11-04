#!/bin/bash

make all \
&& ./polishlookup.out 'A' 'B!'  'C!!' \
&& ./polishlookup.out 'AA|' 'AB|C&' 'AB|C&D>' 'ABCD&|^' 'AB!&!C!D!!^=' \
;
