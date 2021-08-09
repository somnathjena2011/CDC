//Multipath Inheritance
/*
	  A
	 / \
   /   \
   B   C
   \   /
    \ /
     D
D has 2 copies of A's members, one via B and one via C
Avoiding ambiguity:
1. Scope resolution operator
   D d;
   d.B::x=10;
   c.C::x=100;
   //x member of A
2. Using scope resolution operator still there are 2 copies
   of A in D
   Use virtual base class
*/
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	int x;
	A()
	{
		cout<<"A\n";
	}
};
class B:public A
{
public:
	B()
	{
		cout<<"B\n";
	}
};
class C:public A
{
public:
	C()
	{
		cout<<"C\n";
	}
};
class D:public B,public C 
{
public:
	D()
	{
		cout<<"D\n";
	}
};

class E
{
public:
	int x;
	E()
	{
		cout<<"E\n";
	}
};
class F:virtual public E
{
public:
	F()
	{
		cout<<"F\n";
	}
};
class G:virtual public E
{
public:
	G()
	{
		cout<<"G\n";
	}
};
class H:public F,public G 
{
public:
	H()
	{
		cout<<"H\n";
	}
};
int main()
{
	D d;
	d.B::x=10;
	d.C::x=100;
	cout<<d.B::x<<'\n';
	cout<<d.C::x<<'\n';
	H h;
	h.x=10;
	cout<<h.x<<'\n';
	h.x=100;
	cout<<h.x<<'\n';
	cout<<h.x<<'\n';
	F f;
	f.x=20;
	G g;
	g.x=30;
	cout<<f.x<<'\n';
	cout<<g.x<<'\n';
	return 0;
}