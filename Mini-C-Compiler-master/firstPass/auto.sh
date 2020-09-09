#!/bin/sh

rm output/symtab.txt
rm output/intermediate_code.txt 
rm ../secondPass/mips.s 
./firstPass make
../secondPass make
../firstPass
./parser < input/input-factorial.c
cd ../secondPass
./second_pass < ../firstPass/output/intermediate_code.txt

#cd ../firstPass
spim
read "mips.s"
run
4