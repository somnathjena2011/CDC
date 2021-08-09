#! /bin/bash

#input redirection
while read p 
do
	echo $p
done < file2.sh
#pipes
cat file2.sh | while read p
do
	echo $p
done
#internal field separator
while IFS= read -r line
do
	echo $line
done < file2.sh