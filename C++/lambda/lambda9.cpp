#include<bits/stdc++.h>
using namespace std;
int main()
{
	int h=10;
	auto f=[&](){h*=2;return h;};
	cout<<"2h="<<f()<<" h="<<h<<'\n';//20 10
	cout<<"2h="<<f()<<" h="<<h<<'\n';//40 10
	return 0;
}