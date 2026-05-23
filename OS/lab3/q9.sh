#!/usr/bin/bash

read -p "Enter the number of rows: " row
read -p "Enter the number of columns: " col
arr=()
for(( i=0;i<row;i++ ))
do
    for(( j=0;j<col;j++ ))
    do
        read -p "Enter element $((i+1)) $((j+1)): " num
        arr+=($num)
    done
done
echo "The matrix is: "
for(( i=0;i<row;i++ )) 
do
    for(( j=0;j<col;j++ )) 
    do
        echo -n "${arr[$i*$col+$j]} "
    done
    echo
done
echo "The transpose of the matrix is: "
for(( i=0;i<col;i++ )) 
do
    for(( j=0;j<row;j++ )) 
    do
        echo -n "${arr[$j*$col+$i]} "
    done
    echo
done