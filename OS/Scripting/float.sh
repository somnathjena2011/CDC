#! /bin/bash

n1=20.5
n2=5

echo "20.5+5" | bc
echo "20.5/5" | bc
echo "scale=2;20.5/5" | bc
echo "$n1+$n2" | bc
echo "$n1/$n2" | bc

n3=27.2
echo "scale=2;sqrt($n3)" | bc -l
echo "scale=2;3^3" | bc -l
n4=2
n5=3
echo "scale=2;$n4^$n5" | bc -l