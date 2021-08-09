#! /bin/bash
[ $# -ne 2 ] && echo Enter 2 args && exit
[ ! -f $1 ] && echo Enter file && exit
[ $2 -lt 1 -o $2 -gt 4 ] && echo Enter valid column && exit
awk -v column=$2 '{print tolower($column)}' $1 |
sort |
uniq -c |
awk '{print $2,$1}' |
sort -k 2 -rno 1c_output_$2_column.freq