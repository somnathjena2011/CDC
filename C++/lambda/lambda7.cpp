#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h=10;
	auto f=[=]() mutable {h*=2;return h;};
	cout<<"2h="<<f()<<'\n';
	cout<<" h="<<h<<'\n';
	return 0;
}