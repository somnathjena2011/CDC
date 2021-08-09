#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	void disp()
	{
		cout<<"India\n";
	}
};
class B:public A
{
public:
	void disp()
	{
		cout<<"Pakistan\n";
	}
};
int main()
{
	A* a=new B();
	a->disp();
	B* b=new B();
	b->disp();
	return 0;
}