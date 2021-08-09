//pass a functor as compare function to sort
#include<bits/stdc++.h>
using namespace std;
struct compare:public binary_function<int,int,bool>
{
	bool operator()(int a,int b)
	{
		return a>b;
	}
};
int main()
{
	vector<int> v={3,4,1,6,2};
	sort(v.begin(),v.end(),compare());
	for(int el:v)
		cout<<el<<' ';
	cout<<'\n';
}