#! /bin/bash

echo -e "Enter file name :\c"
read file

if [ -f $file ]
then
	if [ -w $file ]
	then
		echo "Type some text. Press ctrl+d to quit."
		cat >> $file
	else
		echo "You don't have write permissions."
	fi
else
	echo "$file not exists"
fi