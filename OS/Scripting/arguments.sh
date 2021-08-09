#! /bin/bash

echo $0 $1 $2 $3

args=("$@") #$@ default variable thatstores arguments, args is an array type variable

echo ${args[0]} ${args[1]}
#first argument i.e. script name not passed to args

echo $@

echo $#