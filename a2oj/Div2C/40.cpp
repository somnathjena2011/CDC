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
void solve(ll a,ll b,ll& ans)
{
	if(b==1)
	{
		ans+=a;
		return;
	}
	if(a==1)
	{
		ans+=b;
		return;
	}
	if(a>b)
	{
		ll c=a/b;
		ll d=a-c*b;
		ans+=c;
		solve(d,b,ans);
	}
	else
	{
		ll e=b;
		ll f=a;
		ll c=e/f;
		ll d=e-c*f;
		ans+=c;
		solve(f,d,ans);
	}
}
int main()
{
	ll a,b,ans=0;
	cin>>a>>b;
	solve(a,b,ans);
	cout<<ans<<'\n';
	return 0;
}