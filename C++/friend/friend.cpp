#include<bits/stdc++.h>
using namespace std;
class A;
class B
{
public:
	void showA(A&);
};
class A
{
private:
	int x;
public:
	A()
	{
		x=10;
	}
	friend void showA(A&);
	friend void B::showA(A&);
	friend class C;
};
class C
{
public:
	void showA(A& a)
	{
		cout<<a.x<<'\n';
	}
};
void showA(A& a)
{
	cout<<a.x<<'\n';
}
void B::showA(A& a)
{
	cout<<a.x<<'\n';
}
int main()
{
	A a;
	B b;
	C c;
	showA(a);
	b.showA(a);
	c.showA(a);
	return 0;
}