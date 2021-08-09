#include<bits/stdc++.h>
using namespace std;
struct Permute
{
	string str;
	Permute(string str):str(str){}
	void operator()(int i)
	{
		if(i==str.size())
		{
			cout<<str<<'\n';
			return;
		}
		for(int j=i;j<str.size();j++)
		{
			swap(str[i],str[j]);
			(*this)(i+1);
			swap(str[i],str[j]);
		}
	}
};
int main()
{
	string str;
	cin>>str;
	Permute permute(str);
	permute(0);
	return 0;
}