#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
int main()
{
	int n,k;
	string s;
	cin>>n>>k;
	cin>>s;
	int l,m,i,j,x;
	string a,b,c;
	if(n==1)
	{
		while(s.length()<k)
			s+=s;
		cout<<s.substr(0,k)<<'\n';
		return 0;
	}
	else if(k==1)
	{
		cout<<s.substr(0,1)<<'\n';
		return 0;
	}
	j=1;
	while(1)
	{
		l=s.length();
		for(j=1;j<l;j++)
		{
			if(s.substr(0,j)<s.substr(j,j))
				break;
		}
		if(j==l)
		{
			if(l>=k)
			{
				cout<<s.substr(0,k)<<'\n';
				return 0;
			}
			else
				s+=s;
		}
		else if(j>=k)
		{
			cout<<s.substr(0,k)<<'\n';
			return 0;
		}
		else
		{
			s=s.substr(0,j);
			while(s.length()<k)
				s+=s;
			if(s.length()>k)
				s=s.substr(0,k);
		}
	}
	return 0;
}