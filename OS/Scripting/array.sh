#! /bin/bash

os=('ubuntu' 'windows' 'kali')
os[4]='mac'
os[0]='mac'
unset os[1]
echo ${os[@]}
echo ${os[1]}
echo ${!os[@]}
echo ${#os[@]}

string=somnath
echo ${string[@]}
echo ${string[0]}
echo ${string[1]}
echo ${#string[@]}