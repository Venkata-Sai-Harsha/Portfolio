#!/usr/bin/bash

read -p "Enter the number of rows: " rows

for (( i=1; i<=$rows; i++ ))
do
    for (( j=$rows; j>=i; j-- ))
    do
        echo -n "  "
    done
    for (( j=1; j<=2*$i-1; j++ ))
    do
        echo -n "* "
    done
    echo ""
done