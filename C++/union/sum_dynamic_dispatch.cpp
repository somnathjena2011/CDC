#include<bits/stdc++.h>
using namespace std;
struct Sum
{
	virtual int myCase() const=0;
};
struct T1:public Sum
{
	int data;
	T1(int i):data(i){}
	int myCase() const override
	{
		return data*1;
	}
};
struct T2:public Sum
{
	int data;
	T2(int i):data(i){}
	int myCase() const override
	{
		return data*2;
	}
};
int main()
{
	const Sum& s1=T1(5);
	const Sum& s2=T2(7);
	cout<<s1.myCase()<<'\n';
	cout<<s2.myCase()<<'\n';
	return 0;
}