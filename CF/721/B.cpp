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
#define rloop0(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>0;i--)
#define sloop0(i,n,s) for(i=0;i<n;i+=s)
int main()
{
	int t,n,i,j,ans;
	cin>>t;
	string s;
	int o,z;
	while(t--)
	{
		cin>>n;
		cin>>s;
		o=z=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='0')
				++z;
			else
				++o;
		}
		if(o==n)
			cout<<"DRAW\n";
		else if(n%2==0)
		{
			cout<<"BOB\n";
		}
		else
		{
			if(z==1)
				cout<<"BOB\n";
			else if(z%2==1)
				cout<<"ALICE\n";
			else
				cout<<"BOB\n";
		}
	}
	return 0;
}