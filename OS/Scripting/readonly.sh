#! /bin/bash

var=31
readonly var
var=20
echo $var

hello(){
	echo Hello
}
hello
readonly -f hello
hello(){
	echo Hello again
}
hello

readonly -f