#!/usr/bin/bash

while true; 
do
    echo "Choose an operation:"
    echo "1. Addition (+)"
    echo "2. Subtraction (-)"
    echo "3. Multiplication (*)"
    echo "4. Division (/)"
    echo "5. Modulo (%)"
    echo "6. Increment (++)"
    echo "7. Decrement (--)"
    echo "8. Exit"

    read -p "Enter the operation: " op

    read -p "Enter the first number: " num1
    read -p "Enter the second number: " num2

    case $op in
        1)
            echo "The sum is: $((num1 + num2))"
            ;;
        2)
            echo "The difference is: $((num1 - num2))"
            ;;
        3)
            echo "The product is: $((num1 * num2))"
            ;;
        4)
            echo "The quotient is: $((num1 / num2))"
            ;;
        5)
            echo "The remainder is: $((num1 % num2))"
            ;;
        6)
            echo "The Increment is: $((num1 + 1))"
            ;;
        7)
            echo "The Decrement is: $((num1 - 1))"
            ;;
        8)
            echo "Invalid operation"
            break
            ;;
    esac
    echo "Do you want to perform another operation? (y/n)"
    read ans
    if [ "$ans" = "n" ]; then
        break
    fi
done