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
	ll t,l,r,n,ans,x,a,b;
	cin>>t;
	while(t--)
	{
		cin>>l>>r;
		ans=0;
		x=1;
		a=l;b=r;
		while(r/x)
		{
			a=l/x;
			a=a*x;
			b=r;
			ans+=((b-a)/x);
			x*=10;
		}
		cout<<ans<<'\n';
	}
	return 0;
}