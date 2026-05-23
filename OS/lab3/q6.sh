#!/usr/bin/bash

read -p "Enter the number of elelments: " num
arr=()
sum=0
for (( i=0; i<num; i++ ))
do
    read -p "Enter element $((i+1)): " num
    arr+=($num)
    sum=$(echo "$sum + $num" | bc)
done
avg=$(echo "scale=2; $sum / $num" | bc)
echo "The array is: ${arr[*]}"
echo "The average is: $avg"