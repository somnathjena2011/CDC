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

class B
{
public:
	B()
	{
		//compiler inserts stub to call A's consturctor
		cout<<"B\n";
	}
private:
	A a;
};
int main()
{
	cout<<"First\n";
	B b;
	cout<<"Second\n";
	B bb=B();
	cout<<"Third\n";
	B bbb={};
	cout<<"Fourth\n";
	B* bbbb=new B();
	return 0;
}