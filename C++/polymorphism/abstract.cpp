#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	int x;
	virtual void fun() = 0;
};

class B:public A 
{
public:
	int y;
	void fun()
	{
		cout<<"A\n";
	}
};

int main()
{
	B b;
	b.fun();
	return 0;
}