#! /bin/bash

print(){
	name=$1
	echo $name
}
print2(){
	local name=$1
	echo $name
}
name=Jena
echo $name
print Jeko
echo $name
print2 Sonu
echo $name