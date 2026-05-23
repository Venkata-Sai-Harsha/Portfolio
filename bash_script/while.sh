#!/usr/bin/bash

n=1
while [ $n -le 3 ]
#while (( $n <= 10 ))
do
    echo $n
    #n=$(( n+1 ))
    ((n++))
    xterm & 
done