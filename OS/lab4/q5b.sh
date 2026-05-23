#!/usr/bin/bash

for (( i=1; i<=10; i++ )) do
    n=$(($1*i))
    echo "$1 x $i = $n"
done