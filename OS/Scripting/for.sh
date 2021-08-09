#! /bin/bash

for v in 1 2 3 4 5
do
	echo $v 
done

for v in {1..5..2}
do
	echo $v 
done

for (( i=0; i<5; i++ ))
do
	echo $i 
done

for command in ls pwd date
do
	echo "--------$command---------"
	$command
done

for item in *
do
	[ -d $item ] && echo $item
done

for file in while.sh sleep.sh
do
	cat $file > catted.sh
done