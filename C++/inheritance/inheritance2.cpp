/*
Modes of inheritance:
public: public members become public and protected
        become protected in sub class
protected: public and protected members both become
           protected in sub class
private: public and protected members both become
         private in sub class
BY DEFAULT ALL private members OF BASE CLASS
CANNOT BE DIRECTLY ACCESSED FROM DERIVED CLASS
*/

#include<bits/stdc++.h>
using namespace std;

class A
{
public:
	int x;
protected:
	int y;
private:
	int z;
};

class B:public A
{
public:
	void dispPublic()
	{
		cout<<x<<'\n';
	}
	void dispProtected()
	{
		cout<<y<<'\n';
	}
	void dispPrivate()
	{
		//error cout<<z<<'\n';
	}
};

class C:protected A
{
public:
	void dispPublic()
	{
		cout<<x<<'\n';
	}
	void dispProtected()
	{
		cout<<y<<'\n';
	}
	void dispPrivate()
	{
		//error cout<<z<<'\n';
	}
};

class D:private A
{
public:
	void dispPublic()
	{
		cout<<x<<'\n';
	}
	void dispProtected()
	{
		cout<<y<<'\n';
	}
	void dispPrivate()
	{
		//error cout<<z<<'\n';
	}
};

int main()
{
	B b;
	C c;
	D d;
	b.x=1;b.y=2;
	c.x=3;c.y=3;
	d.x=4;d.y=5;
	b.dispPublic();
	b.dispPrivate();
	b.dispProtected();
	c.dispPublic();
	c.dispPrivate();
	c.dispProtected();
	d.dispPublic();
	d.dispPrivate();
	d.dispProtected();
	return 0;
}