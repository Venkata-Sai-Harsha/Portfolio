#!/usr/bin/bash

function gcd(){
    local a=$1
    local b=$2
    local r=1
    while [ $r -ne 0 ]
    do
        r=$((a % b))
        a=$b
        b=$r
    done
    echo $a
}

read -p "Enter the first number: " num1
read -p "Enter the second number: " num2

gcd $num1 $num2