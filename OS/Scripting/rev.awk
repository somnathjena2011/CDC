{ arr[NR]=$0 }
END {
	i=NR
	while(i>0){
		print arr[i]
		i=i-1
	}
}