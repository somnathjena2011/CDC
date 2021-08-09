//rvalue is an expression that appears on the right hand of assignment
//lvalue appears on left
//lvalue points to a memory location and allows us
//to use the memory using & operator
#include<bits/stdc++.h>
using namespace std;
int bar()
{
	return 5;
}
void foo(const int& a)
{

}
int main()
{
	// int& foo();
	// foo()=42;
	// cout<<foo()<<'\n';
	// int* p=&foo();
	foo(bar());//ok, rvalue can bind to const lvalue
	return 0;
}