#! /bin/bash

echo "Enter name : "
read name
echo "Entered name : $name"
echo "Enter names: "
read name1 name2 name3
echo "Names: $name1, $name2, $name3"
echo "Enter name same line: "
read -p "username: " user #read on same line
echo "username: $user"
read -sp "password: " pswrd #silent
echo
echo "password: $pswrd"
echo "Enter names:"
read -a names
echo "Names01: ${names[0]}, ${names[1]}"
read
echo $REPLY