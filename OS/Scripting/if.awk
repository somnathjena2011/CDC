$2>5 {n=n+1;pay=pay+$2*$3}
END {
	if (n>0)
	print n, "employees, total pay=", pay, "ave pay=", pay/n
	else
	print " no employees more than $5 an hour"
}