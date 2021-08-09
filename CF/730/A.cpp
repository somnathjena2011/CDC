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
	ll t;
	ull a,b;
	ull x,y,d;
	ull i,j;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		x=min(a,b);
		y=max(a,b);
		if(x==y)
			cout<<0<<' '<<0<<'\n';
		else if(x==0)
			cout<<y<<' '<<0<<'\n';
		else
		{
			d=y-x;
			if(x%d==0)
				cout<<d<<' '<<0<<'\n';
			else
			{
				i=(x/d)*d;
				j=(x/d+1)*d;
				cout<<d<<' '<<min(x-i,j-x)<<'\n';
			}
		}
	}
	return 0;
}