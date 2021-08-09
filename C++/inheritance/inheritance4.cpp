//Multilevel inheritance
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A\n";
	}
};
class B:public A
{
public:
	B()
	{
		cout<<"B\n";
	}
};
class C:public B 
{
public:
	C()
	{
		cout<<"C\n";
	}
};
int main()
{
	C c;
	return 0;
}