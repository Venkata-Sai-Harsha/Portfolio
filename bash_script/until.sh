#!/usr/bin/bash

n=1
until [$n -lt 10]
do
    echo $n
    n=$(( n+1 ))
done
