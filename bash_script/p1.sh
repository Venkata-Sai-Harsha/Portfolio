#!/usr/bin/bash

read -p "Enter the number of columns: " col
read -p "Enter the number of rows: " row

# Declare arrays to store the matrices
declare -A arr1
declare -A arr2
declare -A result

echo "Enter the elements of the first matrix:"
for ((i = 1; i <= row; i++))
do
    for ((j = 1; j <= col; j++))
    do
        read -p "Enter the element of row $i and column $j: " num
        arr1[$i,$j]=$num
    done
    echo
done

echo "Enter the elements of the second matrix:"
for ((i = 1; i <= row; i++))
do
    for ((j = 1; j <= col; j++))
    do
        read -p "Enter the element of row $i and column $j: " num
        arr2[$i,$j]=$num
    done
    echo
done

echo "Matrix 1:"
for ((i = 1; i <= row; i++))
do
    for ((j = 1; j <= col; j++))
    do
        echo -n "${arr1[$i,$j]} "
    done
    echo
done

echo "Matrix 2:"
for ((i = 1; i <= row; i++))
do
    for ((j = 1; j <= col; j++))
    do
        echo -n "${arr2[$i,$j]} "
    done
    echo
done



echo "The product of the two matrices is:"
for ((i = 1; i <= row; i++))
do
    for ((j = 1; j <= col; j++))
    do
        sum=0
        for ((k = 1; k <= col; k++))
        do
            ((sum += arr1[$i,$k] * arr2[$k,$j]))
        done
        result[$i,$j]=$sum
        echo -n "${result[$i,$j]} "
    done
    echo
done
