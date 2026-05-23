#!/usr/bin/bash

read -p "Enter a number: " num

count=1
for (( i=1;i<=$num;i++))
do
   for (( j=1;j<=$num-$i;j++ ))
    do
        echo -n "   "
    done
    for (( k=1;k<=2*($i)-1;k++ ))
    do
        echo -n "$count  "
        ((count++))
    done
    echo ""
done

for (( i=$num-1;i>=1;i--))
do
   for (( j=1;j<=$num-$i;j++ ))
    do
        echo -n "   "
    done
    for (( k=1;k<=2*($i)-1;k++ ))
    do
        echo -n "$count  "
        ((count++))
    done
    echo ""
done