#!/bin/bash


make all && make all -C ../exprgen || exit;

for (( i=0; i<"$1"; i++ ))
do 
	./negation_normal_form.out $(../exprgen/exprgen.out $2 $3)
done;
