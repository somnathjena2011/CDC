/*
->function applied to arguments whose types match with the type
expression invloving type variables
->e.g. templates
->function templates instantiated automatically based on the 
type of the arguments passed
*/
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void Swap(T& x,T& y)
{
	T t=x;
	x=y;
	y=t;
}
int main()
{
	int a=5;int b=7;
	cout<<a<<' '<<b<<'\n';
	Swap(a,b);//same as Swap<int>(a,b)
	cout<<a<<' '<<b<<'\n';
	string c="India";string d="Pakistan";
	cout<<c<<' '<<d<<'\n';
	Swap(c,d);//same as Swap<string>(c,d)
	cout<<c<<' '<<d<<'\n';
	return 0;
}