#! /bin/bash

function hello(){
	echo "Hello"
}

quit(){
	exit
}

function print(){
	echo $@
}

hello
print Ind Pak
quit

echo 4