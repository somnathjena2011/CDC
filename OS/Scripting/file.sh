#! /bin/bash

echo -e "Enter file: \c"
read file
if [ -e $file ]
then
	echo "$file found"
else
	echo "$file not found"
fi

if [ -f $file ]
then
	echo "$file is file"
else
	echo "$file is not file"
fi

if [ -d $file ]
then
	echo "$file is directory"
else
	echo "$file is not directory"
fi

if [ -s $file ]
then
	echo "$file not empty"
else
	echo "$file empty"
fi