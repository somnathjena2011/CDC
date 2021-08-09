/*
COPY CONSTRUCTOR
1. used to initialize an object using another object of same class
2. Class(const Class& ob);
->Copy constructor called in following cases:
1. when a function returnd an object of class as value
2. when we pass an object of class as parameter by value
3. when an object is constructed based on another object
4. when compiler creates a temporary object
->If we do not provide a copy constructor, compiler will
provide a default copy constructor
1. Default copy constructor does shallow copy
   i.e. it copies all members' values as it is
   so pointers in both objects point to same memory location
2. To do deep copy, i.e. to make pointers/references in
   2 objects point to diff memory locations, we need to
   define our own copy constructor
->Copy constructor is called when an object is created from another
->Assignment operator is called when an already initialized object
  is assigned a new value from an existing object
A a,b;
A c=a;//copy constructor called
b=a;  //assignment operator called
1. Why object passed as reference in copy constructor?
   because whenever an object is passed as value to function
   copy constructor is called, so it would have called
   an infinite chain of copy constructor calls
2. Why const?
   so that the object doesn't modify the contents of the other object
*/
#include<bits/stdc++.h>
using namespace std;
class String
{
public:
	char* s;
	int size;
	String(const char* str=NULL);//constructor
	//String(const String&);       //copy constructor
	~String()                    //destructor
	{
		delete s;
	}
	void print()
	{
		cout<<s<<'\n';
	}
	void change(const char*);
};

String::String(const char* str)
{
	size=strlen(str);
	s=new char[size+1];
	strcpy(s,str);
}

// String::String(const String& copy)
// {
// 	size=strlen(copy.s);
// 	s=new char[size+1];
// 	strcpy(s,copy.s);
// }

void String::change(const char* str)
{
	delete s;
	size=strlen(str);
	s=new char[size+1];
	strcpy(s,str);
}

int main()
{
	String str1("India");
	String str2=str1;
	str1.print();
	str2.print();
	str2.change("Pakistan");
	str1.print();//if default copy constructor was used this would
	//have printed Pakistan as it copies whatever the members of one object has
	//i.e. shallow copy
	str2.print();
	//if there was no copy constructor destructor would have caused error
	//Reason: destructor of str1 destroys its instance of s's memory
	//but str2 had the same memory address of that string
	//so when its destructor called and it calls delete for that
	//memory location, it gives error as that location already freed
	return 0;
}