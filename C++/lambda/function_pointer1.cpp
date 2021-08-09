#include<bits/stdc++.h>
using namespace std;
int (*p2f)(int,char,char);
int f(int a,char b,char c)
{
	return a+b+c;
}
int g(int a,char b,char c)
{
	return a+b;
}
int main()
{
	p2f=f;
	if(p2f==&f)
		cout<<"Same\n";
	if(p2f==f)
		cout<<"Same\n";
	int x=(*p2f)(12,'a','b');
	int y=p2f(12,'a','b');
	p2f=g;
	if(p2f==f)
		cout<<"Same\n";
	if(p2f==g)
		cout<<"Diff\n";
	int z=p2f(12,'a','b');
	cout<<x<<'\n';
	cout<<y<<'\n';
	cout<<z<<'\n';
	return 0;
}