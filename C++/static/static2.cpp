/*
->static member functions do not have this pointer
simply because they are shared among all objects, and thus
cannot simply refer to a specific object
->static member function cannot be virtual
because static members belong to class
while virtual functions called based on the type of object
->2 functions with same name and same parameter lost cannot 
be pverloaded when one is static
->statuc member function cannot be declared static
*/
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	int x;
	static void fun()
	{
		this->x=0;//THIS IS UNAVILABLE FOR
				  //STATIC MEMBER FUNCTIONS
	}
};
class B
{
public:
	int fun(){return 0;}
	static int fun(){return 1;}//cannot overload same prototype funs
							   //even when one is static
};
int main()
{
	// A a;
	// A::fun();
	B b;
	b.fun();
	return 0;
}