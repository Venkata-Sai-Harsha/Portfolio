#!/usr/bin/bash

read -p "Enter the file name: " file

echo "The lowest number is: " 
min= cat $file | sort -n | head -1
echo "The highest number is: "
max= cat $file | sort -n | tail -1