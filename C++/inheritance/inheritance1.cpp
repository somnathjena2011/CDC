#include<bits/stdc++.h>
using namespace std;
class Parent
{
public:
	int id_p;
};
class Child: public Parent
{
public:
	int id_c;
};
int main()
{
	Child ob;
	ob.id_c=7;
	ob.id_p=9;
	cout<<"P="<<ob.id_p<<'\n';
	cout<<"C="<<ob.id_c<<'\n';
	return 0;
}