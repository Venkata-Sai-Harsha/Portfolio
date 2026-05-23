#!/usr/bin/bash

read -p "Enter first string: " s1
read -p "Enter second string: " s2
s3=$s1$s2
length=${#s3}
echo "Length of concatenated string is $length"