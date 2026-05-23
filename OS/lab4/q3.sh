#!/usr/bin/bash

read -p "Enter a number: " num

echo "The prime numbers below $num are: "

for (( i=2; i<num; i++ )) do
    is_prime=true
    for (( j=2; j<i; j++ )) do
        if [[ $(( i % j )) -eq 0 ]]
        then
            is_prime=false
            break
        fi
    done
    if $is_prime
    then
        echo $i
    fi
done