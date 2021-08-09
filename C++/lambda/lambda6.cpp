#include<bits/stdc++.h>
using namespace std;
struct functor
{
	int& x;
	functor(int& x):x(x){}
	void operator()(){cout<<x<<'\n';}
};
int main()
{
	int x=42;
	//lambda captured at the time of evaluation itself
	auto f1=[=](){cout<<x<<'\n';};
	x=8;
	f1();//output 42, not 8
	int y=42;
	functor f2(y);
	y=8;
	f2();
	return 0;
}