#! /bin/bash

check(){
	local file=$1
	[ -f $file ] && return 0 || return 1
}

[[ $# -eq 0 ]] && echo No args && exit

if ( check $1 )
then
	echo $1 is a file
else
	echo $1 is not file
fi