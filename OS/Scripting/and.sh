#! /bin/bash

age=50

if [ $age -gt 18 ] && [ $age -lt 30 ]
then
	echo Valid
else
	echo Invalid
fi

if [ $age -gt 18 -a $age -lt 30 ]
then
	echo Valid
else
	echo Invalid
fi