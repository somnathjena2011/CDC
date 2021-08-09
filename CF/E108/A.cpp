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
	ll t,r,b,d,x;
	cin>>t;
	while(t--)
	{
		cin>>r>>b>>d;
		x=min(r,b);
		r-=x;
		b-=x;
		if(r>0)
		{
			if(d*x>=r)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else if(b>0)
		{
			if(d*x>=b)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
			cout<<"YES\n";
	}
	return 0;
}