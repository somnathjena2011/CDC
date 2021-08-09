#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,t;
	cin>>s;
	cin>>t;
	int n=s.size();
	int m=t.size();
	int i,j,f;
	long hashA=0,hashB=0;
	long base=26;
	long p=1;
	long mod=1e9+7;
	for(i=0;i<m;i++)
	{
		hashB=((hashB*base)%mod+(t[i]-'a')%mod)%mod;
		hashA=((hashA*base)%mod+(s[i]-'a')%mod)%mod;
		p=(p*base)%mod;
	}
	vector<int> indices;
	for(i=0;i<n-m+1;i++)
	{
		if(hashA==hashB)
		{
			f=1;
			for(j=0;j<m;j++)
			{
				if(t[j]!=s[i+j])
				{
					f=0;
					break;
				}
			}
			if(f)
				indices.push_back(i);
		}
		if(i+m<n)
			hashA=((hashA*base)%mod+(s[i+m]-'a')%mod-(p*(s[i]-'a'))%mod+mod)%mod;
	}
	for(int ind:indices)
		cout<<ind<<' ';
	cout<<'\n';
	return 0;
}