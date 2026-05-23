#!/usr/bin/bash

echo "Hello, World!"
read -p "Enter your name: " name
read -p "Enter your age: " age
sum=$((name + age))
echo "$sum"