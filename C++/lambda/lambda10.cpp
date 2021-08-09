#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=8;
	auto f = [=]()mutable{
		int j=2;
		auto m = [&]{i/=j;};
		m();
		cout<<"inner="<<i<<'\n';
	};
	f();
	cout<<"outer="<<i<<'\n';
	return 0;
}