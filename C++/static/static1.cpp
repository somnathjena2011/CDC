/*
->static members are mebers of class declared as static
->only one copy of the member is created for the entire class
and is shared among all objects of that class
->It is initialized to 0 when first object of the class created,
no other initializations allowed
->visible only within the class, but its lifetime is the entire 
program
*/
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	int x;
	A(int x)
	{
		cout<<"A\n";
	}
};

class B
{
public:
	static A a;
	static int x;
	int y;
	B()
	{
		cout<<"B\n";
	}
	static A getA()
	{
		//static member functions allowed to access only
		//static members and other static member functions
		return a;
	}
};

A B::a=*(new A(5));
int B::x=1;

int main()
{
	B b1,b2,b3;
	//OUTPUT:
	/*
	A
	B
	B
	B
	A is printed only once
	Reason: static members are only declared in the class
	and not defined
	When we provide a definition to A, it is iniliazed only 
	that one time
	*/
	//A a=b.getA();
	/*
	This will cause linking error.
	i.e. when we try to access static member without
	its explicit defintion(undefined reference)

	Hence static members must be explicitly defined
	OUTSIDE THE CLASS USING SCOPE RESOLUTION OPERATOR
	*/
	//A c=b.getA();
	A a=B::getA();
	B::x=5;
	return 0;
}