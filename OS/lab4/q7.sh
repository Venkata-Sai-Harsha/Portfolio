#!/usr/bin/bash

function factorial {
  if (( $1 <= 1 )); then
    echo 1
  else
    echo $(( $1 * $(factorial $(( $1 - 1 )) ) ))
  fi
}

read -p "Enter a number: " num

echo "The factorial of $num is: $(factorial $num)"