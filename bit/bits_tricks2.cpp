#include<bits/stdc++.h>
using namespace std;
/*
2's complement=1's complement + 1
~num+1=-num
*/
int twosCompl(int x)
{
	return -x;
	//or return (~x)+1;
}
/*
clear lowest set bit
x&(x-1)
x-1 inverts all bits till it encounters lowest 1 and 
also invert that
so x&(x-1) returns all bits as it is above lowest 1
and all 0s from there
*/
int clearLowest(int n)
{
	return n&(n-1);
}
/*
Get lowest set bit
x&~(x-1) or x&-x
in -x all bits higher than lowest set bit are inverted
lowest set bit remains 1 and below it all 0s
*/
int getLowest(int n)
{
	return n&(-n);
}
/*
set lowest unset bit
x|x+1
*/
int setLowest(int n)
{
	return n|(n+1);
}
/*
get Lowest unset bit
x|~(x+1)
(all other bits set to 1)
*/
int getLowestUnset(int n)
{
	return n|~(n+1);
}
/*
clear all bits from lsb to ith bit
AND with ~(1<<(i+1)-1)
e.g.
n=   101101101010111
i=6
mask=111111110000000
1<<7=000000010000000
     -             1
     _______________
     000000001111111
   ~=111111110000000=mask
*/
int clearLSB(int n,int i)
{
	int mask=~((1<<(i+1))-1);
	return n&mask;
}
/*
clear all bits from msb to ith bit
AND with (1<<i)-1
e.g.
n=   10110110101011
i=6
mask=00000000111111
    =00000001000000-1
*/
int clearMSB(int n,int i)
{
	int mask=(1<<i)-1;
	return n&mask;
}
/*
upper to lower case=> ch | ' '
lower to upper case=> ch & '_'
*/
/*
count no of set bits in n
while(n)
{
	n=n&(n-1);
	++count;
}
*/
int countSet(int n)
{
	int ans=0;
	while(n)
	{
		n&=(n-1);
		++ans;
	}
	return ans;
}
int log2(int n)
{
	int ans=0;
	while(n>>=1)
		++ans;
	return ans;
}
int main()
{
	cout<<clearLowest(7)<<'\n';
	cout<<getLowest(10)<<'\n';
	cout<<clearLSB(29,3)<<'\n';
	cout<<clearMSB(215,3)<<'\n';
	cout<<countSet(23)<<'\n';
	return 0;
}