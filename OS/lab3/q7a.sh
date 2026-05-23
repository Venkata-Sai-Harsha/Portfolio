#!/usr/bin/bash 

read -p "Enter the number of rows: " rows

for (( i=$rows; i>=1; i-- ))
do
    for (( j=1; j<=$i; j++ ))
    do
        echo -n "* "
    done
    echo ""
done