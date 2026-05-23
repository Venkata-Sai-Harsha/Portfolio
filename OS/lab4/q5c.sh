#!/usr/bin/bash

read num < input.txt
for (( i=1; i<=10; i++ )) do
    n=$((num*i))
    echo "$num x $i = $n"
done