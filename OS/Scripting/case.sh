#! /bin/bash

vehicle=$1
echo -e "Enter a char :\c"
read value

case $vehicle in
	"car" )
	echo "rent of $vehicle is 100" ;;
	"van" )
	echo "rent of $vehicle is 200" ;;
	* )
	echo "rent of $vehicle is 500" ;;
esac

case $value in
	[a-z] )
	echo "Lowercase" ;;
	[A-Z] )
	echo "Uppercase" ;;
	[0-9] )
	echo "Digit" ;;
	? )
	echo "Some character" ;;
	* )
	echo "Not a character" ;;
esac