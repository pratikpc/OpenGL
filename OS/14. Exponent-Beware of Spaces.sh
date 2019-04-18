#!/bin/bash

echo "enter number"
read a
read b
res=1
#BEWARE OF SPACES
#BEWARE OF SPACES
#BEWARE OF SPACES
for ((i = 0 ; i < b ; i++)); do
    res=$((res*a))
done

echo "$res"
