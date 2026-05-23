#!/usr/bin/bash

read -p "Enter the length: " length
read -p "Enter the breadth: " breadth
read -p "Enter the radius: " radius
pi=$((22/7))

echo "The area of the rectangle is: $((length * breadth))"
echo "The perimeter of the rectangle is: $((2 * (length + breadth)))"
echo "The area of the circle is: "$(echo "3.14 * $radius * $radius" | bc)
echo "The circumference of the circle is: "$(echo "2 * 3.14 * $radius" | bc)