#!/usr/bin/bash

read -p "Enter the no.of elements: " n
t1=0
t2=1
echo "The Fibonacci series is: "
for (( i=0; i<n; i++ )) do
    echo -n "$t1 "
    fn=$((t1 + t2))
    t1=$t2
    t2=$fn
done