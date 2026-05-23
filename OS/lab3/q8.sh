#!/usr/bin/bash

read -p "Enter the number of rows: " row
read -p "Enter the number of columns: " col
arr=()
arr1=()
echo "Enter the elements of the first matrix: "
for (( i=0; i<row; i++ ))
do
    for (( j=0; j<col; j++ ))
    do
        read -p "Enter element $((i+1)) $((j+1)): " num
        arr+=($num)
    done
done
echo "Enter the elements of the second matrix: "
for (( i=0; i<row; i++ ))
do
    for (( j=0; j<col; j++ ))
    do
        read -p "Enter element $((i+1)) $((j+1)): " num
        arr1+=($num)
    done
done
echo "The first matrix is: "
for (( i=0; i<row; i++ ))
do
    for (( j=0; j<col; j++ ))
    do
        echo -n "${arr[$i*$col+$j]} "
    done
    echo
done
echo "The second matrix is: "
for (( i=0; i<row; i++ ))
do
    for (( j=0; j<col; j++ ))
    do
        echo -n "${arr1[$i*$col+$j]} "
    done
    echo
done
echo "The sum of the two matrices is: "
for (( i=0; i<row; i++ ))
do
    for (( j=0; j<col; j++ ))
    do
        sum=$(echo "${arr[$i*$col+$j]} + ${arr1[$i*$col+$j]}" | bc)
        echo -n "$sum "
    done
    echo
done