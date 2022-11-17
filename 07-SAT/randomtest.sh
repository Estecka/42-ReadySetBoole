#!/bin/bash


make all && make all -C ../exprgen || exit;

for (( i=0; i<"$1"; i++ ))
do 
	./SAT.out $(../exprgen/exprgen.out $2 $3)
done;
