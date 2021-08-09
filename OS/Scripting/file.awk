{pay=pay+$2*$3}
END {
	print NR, "Employees ", "total pay is ", pay,
	"average pay is ", pay/NR
}