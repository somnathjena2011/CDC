#include<bits/stdc++.h>
using namespace std;
typedef int (*p2f)(int,char,char);
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
	p2f f1=f;
	p2f f2=g;
	int x=f1(12,'a','b');
	int y=f2(12,'a','c');
	cout<<x<<'\n';
	cout<<y<<'\n';
	return 0;
}