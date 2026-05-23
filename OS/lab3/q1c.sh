#1/usr/bin/bash

read -p "Enter a number: " x
if [ $((x%2)) -eq 0 ]; 
then
  echo "Number is Even"
else
  echo "Number is Odd"
fi