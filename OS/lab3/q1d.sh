#!/usr/bin/bash

read -p "Enter a number1: " x
read -p "Enter a number2: " y
temp=$x
let x=$y
let y=$temp
echo "After swapping: $x $y"