#!/bin/bash

echo "enter number"
read a
read b

for ((i = 0 ; i <= b ; i++)); do
    echo "$a * $i = $((a*i))"
done
