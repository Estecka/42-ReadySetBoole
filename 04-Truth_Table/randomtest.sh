#!/bin/bash


make all && make all -C ../exprgen || exit;

for (( i=0; i<"$1"; i++ ))
do 
	./truth_table.out $(../exprgen/exprgen.out $2 $3)
done;
