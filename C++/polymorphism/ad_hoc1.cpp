/*
->C/C++-> statically typed, unsafe(casting,union,pointer arithmetic)
->Python/JS->dynamically tyoed, safe
->Java-> statically typed, safe
->overloading
->one or more constructs with different types refered to 
by the same name
->function overloading and operator overloading
*/
#include<bits/stdc++.h>
using namespace std;
template<class T>
void f(T t)
{
	cout<<"1 called\n";
}
void f(int i)
{
	cout<<"2 called\n";
}
template<class T>
void f(T*)
{
	cout<<"3 called\n";
}
void g(int a)
{
	cout<<"4 called\n";
}
void g(double a,double b=3.2)
{
	cout<<"5 called\n";
}
int main()
{
	//overload resolution
	f(5);//exact match
	f(5.5);//template one
	f('a');//template one
	int a;
	f(&a);//more speficalized match
	g(2.3);//exact match
	return 0;
}