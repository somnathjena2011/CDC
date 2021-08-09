#! /bin/bash

count=10
if [ $count -eq 10 ]
then
	echo "condition true"
fi

if (($count>9))
then
	echo "cond2 true"
fi

word=abc
if [ $word == "abc" ]
then
	echo "cond3 true"
fi

if [[ $word < "a" ]]
then
	echo "cond4 true"
elif [[ $word < "z" ]]
then
	echo "cond4 2nd true"
else
	echo "cond4 false"
fi