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
	int t,c,w,i,e,x;
	cin>>t;
	cin>>x;string s;
	for(c=1;c<=t;c++)
	{
		cin>>w>>e;
		s="";
		for(i=0;i<20;i++)
			s=s+"RSP";
		cout<<"Case #"<<c<<": "<<s<<'\n';
	}
	return 0;
}