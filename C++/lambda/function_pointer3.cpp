#include<bits/stdc++.h>
using namespace std;
class A;
int (A::*p2f)(int,char,char);
class A
{
public:
	int f(int a,char b,char c)
	{
		return a+b+c;
	}
};
int main()
{
	p2f=&A::f;
	if(p2f==&A::f)
		cout<<"Same\n";
	A a;
	int x=(a.*p2f)(12,'a','b');
	cout<<x<<'\n';
	return 0;
}