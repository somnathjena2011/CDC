#include<bits/stdc++.h>
using namespace std;
template<typename T>
void fill(vector<int>& v,T done)
{
	int i=0;
	while(!done())
		v.push_back(i++);
}

int main()
{
	vector<int> vec;
	fill(vec,[&]{
		int sum=0;
		for_each(vec.begin(),vec.end(),[&](int i){sum+=i;});
		return sum>=10;
	});
	for(int el:vec)
		cout<<el<<' ';
	cout<<'\n';
	return 0;
}