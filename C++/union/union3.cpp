#include<bits/stdc++.h>
using namespace std;
typedef int (*int2int)(int);
class Sum
{
public:
	virtual int myCase() const =0;
};
class T1:public Sum
{
public:
	int i;
	T1(int i):i(i){}
	int myCase() const override
	{
		return i*2;
	}
};
class T2:public Sum
{
public:
	int2int i;
	T2(int2int i):i(i){}
	int myCase() const override
	{
		return i(0);
	}
};
int succ(int i)
{
	return i+1;
}
int main()
{
	const Sum& s1=T1(3);
	const Sum& s2=T2(succ);
	cout<<s1.myCase()<<'\n';
	cout<<s2.myCase()<<'\n';
	return 0;
}