#include<bits/stdc++.h>
using namespace std;
struct mod:public unary_function<int,int>
{
	int m;
	mod(int m):m(m){}
	int operator()(int a)
	{
		return a%m;
	}
};
int main()
{
	vector<int> in={5,6,3,1,9,2};
	vector<int> out1(in.size());
	vector<int> out2(in.size());
	int m=5;
	transform(in.begin(),in.end(),out1.begin(),mod(m));
	transform(in.begin(),in.end(),out2.begin(),[m](int a){return a%m;});
	for(int el:out1)
		cout<<el<<' ';
	cout<<'\n';
	for(int el:out2)
		cout<<el<<' ';
	cout<<'\n';
	return 0;
}