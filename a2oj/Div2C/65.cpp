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
ll lights[1005];
ll power(ll x,ll y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x;
	if(x==1)
		return 1;
	if(x==0)
		return 0;
	ll z=power(x,y/2);
	if(y%2==0)
		return (z*z)%mod;
	else
		return (((x*z)%mod)*z)%mod;
}
ll modInv(ll x)
{
	return power(x,mod-2);
}
int main()
{
	ll n,m,i,j,k;
	cin>>n>>m;
	loop1(i,n)
	lights[i]=0;
	ll sum=0;
	loop1(i,m)
	{
		cin>>j;
		lights[j]=1;
		++sum;
	}
	ll rem=n-sum;
	ll dp[n+1];
	loop1(i,n)
	dp[i]=1;
	for(i=2;i<=n;i++)
		dp[i]=(2*dp[i-1])%mod;
	ll fact[n+1];
	fact[0]=fact[1]=1;
	for(i=2;i<=n;i++)
		fact[i]=(i*fact[i-1])%mod;
	vector<pair<ll,ll>> v;
	ll s,e;
	for(i=1;i<=n;i++)
	{
		if(!lights[i])
		{
			s=e=i;
			for(j=i+1;j<=n;j++)
			{
				if(lights[j])
					break;
				e=j;
			}
			i=j;i--;
			if(s==1)
				v.pb({e-s+1,1});
			else if(e==n)
				v.pb({e-s+1,1});
			else
				v.pb({e-s+1,dp[e-s+1]});
		}
	}
	ll ans=fact[rem];
	for(auto p:v)
	{
		ans=(ans*modInv(fact[p.ff]))%mod;
		ans=(ans*p.ss)%mod;
	}
	cout<<ans<<'\n';
	return 0;
}