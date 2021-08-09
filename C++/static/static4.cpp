#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	A()
	{
		cout<<"A\n";
	}
	~A()
	{
		cout<<"~A\n";
	}
};
int check()
{
	return 50;
}
void fun()
{
	static int i=check();
	cout<<i<<'\n';
	static A a;
}
int main()
{
	cout<<"main\n";
	fun();
	cout<<"~main\n";
	return 0;
}