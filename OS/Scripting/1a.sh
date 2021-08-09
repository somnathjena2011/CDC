#! /bin/bash

gcd(){
	! (( $1%$2 )) && echo $2 || gcd $2 $(( $1%$2 ))
}

abs(){
	echo $(( $1<0 ? -1*$1 : $1 ))
}

IFS=, read -a args<<<$1
if (( ${#args[@]}<2 || ${#args[@]}>10 ))
then
	echo "Invalid args";exit
fi

ans=$(abs ${args[0]})
for i in ${args[@]}
do
	ans=$(gcd $ans $(abs i))
done

echo $ans