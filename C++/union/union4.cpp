#include<bits/stdc++.h>
using namespace std;
struct Sum
{
	virtual int myCase() const=0;
};
struct Int:public Sum
{
	int data;
	Int(int i):data(i){}
	int myCase() const override
	{
		return data+1;
	}
};
struct IntInt:public Sum
{

};
struct Int1:public IntInt
{
	int data;
	Int1(int i):data(i){}
	int myCase() const override
	{
		return data+2;
	}
};
struct Int2:public IntInt
{
	int data;
	Int2(int i):data(i){}
	int myCase() const override
	{
		return data+3;
	}
};
int main()
{
	const Sum& s1=Int(10);
	const IntInt& i1=Int1(12);
	const IntInt& i2=Int2(14);
	const Sum& s2=i1;
	const Sum& s3=i2;
	cout<<s1.myCase()<<'\n';
	cout<<s2.myCase()<<'\n';
	cout<<s3.myCase()<<'\n';
	return 0;
}