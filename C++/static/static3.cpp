/*
->static members have lifetime as the lifetime of the program
*/
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A\n";
	}
	~A()
	{
		cout<<"~A\n";
	}
};

class B
{
public:
	static A a;
	B()
	{
		cout<<"B\n";
	}
	~B()
	{
		cout<<"~B\n";
	}
};

A B::a;

int main()
{
	B b;

	//1st B's destructor called
	//then A's at last
	return 0;
}