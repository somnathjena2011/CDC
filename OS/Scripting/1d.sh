#! /bin/bash

[ $# -lt 1 ] && length=16 || length=$1
[ $length -lt 0 ] && echo Invalid length && exit
cat /dev/urandom | tr -dc 'a-zA-Z0-9_' | head -c $length