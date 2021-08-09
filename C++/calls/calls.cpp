#include<bits/stdc++.h>
using namespace std;
void f(int a,int b){a++;b--;}			//Call By Value
void g(int& a,int& b){a++;b--;}			//Call By Reference
void h(int* a,int* b){(*a)++;(*b)--;}	//Call by Address
#define e(a,b) (a*b)					//Call By Name

int main()
{
	int x=3,y=4,z=5;
	f(x,y);		//CBV x=3,y=4
	cout<<"x="<<x<<" y="<<y<<'\n';
	g(x,y);		//CBR x=4,y=3
	cout<<"x="<<x<<" y="<<y<<'\n';
	h(&x,&y);	//CBA x=5,y=2
	cout<<"x="<<x<<" y="<<y<<'\n';
	g(z,z);		//CBR z=5
	cout<<"z="<<z<<'\n';
	cout<<e(x+1,y+1)<<'\n';//CBN x+1*y+1=x+y+1=8
	return 0;
}