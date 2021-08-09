#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	int x;
	virtual void show()=0;
};
class B:public A
{
public:
	void show()
	{
		cout<<"B\n";
	}
};
class C:public A
{

};
class D
{
public:
	int x;
	virtual void fun()=0;
	D(int i)
	{
		x=i;
		cout<<"D\n";
	}
};
class E:public D
{
public:
	int y;
	void fun()
	{
		cout<<"x="<<x<<" y="<<y<<'\n';
	}
	E(int i,int j):D(i),y(j){}
};
int main()
{
	//A a;//Error->cannot declare variable of abstract type A
	A* a=new B();
	a->show();
	//C c;//error->derived class doesn;t override abstract func 
	    //of base class then it also becomes abstract
	//can have constructor of base abstract class
	E e(1,2);
	e.fun();
	D* d=new E(3,4);
	d->fun();
	return 0;
}