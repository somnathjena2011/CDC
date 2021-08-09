#include<bits/stdc++.h>
using namespace std;
int add(int a,int b){return a+b;}
int sub(int a,int b){return a-b;}
int mul(int a,int b){return a*b;}
int divi(int a,int b){return a/b;}
int Switch(int a,int b,int (*f)(int,int))
{
	return f(a,b);
}
int main()
{
	int a=10;int b=2;
	cout<<Switch(a,b,add)<<'\n';
	cout<<Switch(a,b,sub)<<'\n';
	cout<<Switch(a,b,mul)<<'\n';
	cout<<Switch(a,b,divi)<<'\n';
	return 0;
}