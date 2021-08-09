#! /bin/bash

n1=20
n2=5

echo $(( n1 + n2 ))

echo $(expr $n1 + $n2 )
echo $(expr $n1 \* $n2 )
echo $(expr $n1 / $n2 )