#!/usr/bin/bash

#cat fwhile.sh | while read p
#while read p
while IFS= read -r line
do
    echo $line
done < fwhile.sh