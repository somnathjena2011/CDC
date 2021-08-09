/*
->functors/function objects are functions with states
->encapsulate function pointers, use templates and polymorphism
->has its own type
->functor is a class with 0/more private members and an overloaded
  operator() to execute functions
->usually faster than ordinary functions
*/
#include<bits/stdc++.h>
using namespace std;
int f(int a,int b)
{
	return a+b;
}
class Functor
{
public:
	Functor(int a,int b)
	{
		int c=a;
	}
	int operator()(int a,int b)
	{
		return a+b;
	}
};
int main()
{
	int x=5;
	int y=7;
	int z=f(x,y);
	Functor func(x,y);
	int w=func(x,y);
	cout<<z<<' '<<w<<'\n';
	return 0;
}