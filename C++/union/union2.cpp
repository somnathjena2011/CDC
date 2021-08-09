#include<bits/stdc++.h>
using namespace std;
enum Tag
{
	FIELD1,
	FIELD2
};
typedef int (*int2int)(int);
union Union
{
	int i1;
	int2int i2;
	Union(int i):i1(i){}
	Union(int2int i):i2(i){}
};
struct Sum
{
	Tag tag;
	Union u;
	Sum(int i):tag(FIELD1),u(i){}
	Sum(int2int i):tag(FIELD2),u(i){}
};
int succ(int i)
{
	return i+1;
}
int myCase(Sum sum)
{
	switch(sum.tag)
	{
		case FIELD1:return sum.u.i1;
		case FIELD2:return sum.u.i2(0);
	}
}
int main()
{
	Sum s1(2);
	Sum s2(succ);
	cout<<myCase(s1)<<'\n';
	cout<<myCase(s2)<<'\n';
	return 0;
}