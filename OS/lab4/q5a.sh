#!/usr/bin/bash

read -p "Enter a number: " num

for (( i=1; i<=10; i++ )) do
    n=$((num*i))
    echo "$num x $i = $n"
done