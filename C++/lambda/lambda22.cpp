#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	cin>>str;
	auto f=[&](auto self,int i){
		if(i==str.size())
		{
			cout<<str<<'\n';
			return;
		}
		for(int j=i;j<str.size();j++)
		{
			swap(str[i],str[j]);
			self(self,i+1);
			swap(str[i],str[j]);
		}
	};
	f(f,0);
	return 0;
}