#!/usr/bin/bash

function sai(){
    local name=$1 
    echo "The name is $name"
}

name="Tom"
echo "The name is $name : Before"

sai sai

echo "The name is $name : After"