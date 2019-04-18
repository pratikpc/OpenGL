#!/bin/sh

echo "enter amt variables"
read a

if [ $a -lt 1000 ]
then
t=2
d=10

else
t=5
d=20

fi

a=$((a+(a*t/100)-(a*d/100)))
echo "$a"
