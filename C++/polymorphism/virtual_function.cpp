/*
Virtual functions:
->Function overriding
->Runtime polymorphism,compiler at runtime chooses which function
  to execute
->Can use super class's pointer to instantiate sub class objects
->In that case whenever we call a function using sub class pointer
  the function called will be that of base class and not of subclass
->If we want sub class' function to be called we have to declare
  the function in parent class as virtual
->Compiler creates a virtual table for the base class[VTABLE]
  as well as for all the derived classes at compile time.
->VTABLE created for all classes that have a virtual function
  or are derived from a class having virtual function
->VTABLES have function pointers in them used to dynamically bind
  the virtual functions
->Now functions will be called depending on the object and not the pointer
->VTABLES are formed at compile time, but are STATIC arrays
  so all the object instances point to the SAME VTABLE
->Virtual pointer- secret data member of class with virtual function
  can check by seeing diff btwn size of class with and without virtual function
->vptr is added to base class and inherited by derived class
->compiler makes vptr to point to VTABLE by adding code to constructor
->So when we create a sub class object but using pointer of super class
  constructor of sub class gets called, and so the vptr points
  to VTABLE of derived class
  Base *ob=new Derived();
->This is LATE BINDING/DYNAMIC BINDING/RUNTIME POLYMORPHISM
->virtual functions CANNOT BE STATIC
  because virtual functions are invoked/determined based on 
  which class' instance is used to invoke them
*/
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	void f1()
	{
		cout<<"A1\n";
	}
	virtual void f2()
	{
		cout<<"A2\n";
	}
	virtual void f3()
	{
		cout<<"A3\n";
	}
	virtual void f4()
	{
		cout<<"A4\n";
	}
};
class B:public A
{
public:
	void f1()
	{
		cout<<"B1\n";
	}
	void f2()
	{
		cout<<"B2\n";
	}
	void f4(int x)
	{
		cout<<"B4\n";
	}
};
int main()
{
	A* a;
	B b;
	a=&b;
	a->f1();//early binding
	a->f2();//late binding
	a->f3();//late binding
	a->f4();//late binding
	//a->f4(5)//early binding but error, as pointer is of base type
	//and there is no such function in base class
	b.f1();
	b.f2();
	b.f3();
	//b.f4();
	B* c=new B();
	c->f1();
	c->f2();
	c->f3();
	c->f4(5);
	return 0;
}