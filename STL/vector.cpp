#include<bits/stdc++.h>
using namespace std;
int main()
{
	vector<int> v(100,1);
	cout<<v.size()<<'\n';
	v.push_back(0);
	cout<<v.size()<<'\n';
	v.pop_back();
	v.pop_back();
	cout<<v.size()<<'\n';
	return 0;
}