#!/usr/bin/bash

read -p "Enter a number: " num
fact=1
#for (( i=1; i<=num; i++ ))
for i in $(seq 1 $num)
do
    fact=$((fact*i))
done
echo "Factorial of $num is $fact"