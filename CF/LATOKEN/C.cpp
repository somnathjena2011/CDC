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
ll a[400005],b[400005];
ll i1[400005],i2[400005];
ll f[400005];
ll power(ll x,ll y)
{
	ll ans=1;ll n=x;
	while(y)
	{
		if(y&1)
			ans=(ans*n)%mod;
		n=(n*n)%mod;
		y>>=1;
	}
	return ans;
}
int main()
{
	ll t,n,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop1(i,n)
		{
			cin>>a[i];
			i1[a[i]]=i;
		}
		loop1(i,n)
		{
			cin>>b[i];
			i2[b[i]]=i;
			f[i]=0;
		}
		ll c=0;
		loop1(i,n)
		{
			if(f[i])
				continue;
			j=i;++c;
			while(!f[j])
			{
				f[j]=1;
				j=b[i1[j]];
			}
		}
		cout<<power(2,c)<<'\n';
	}
	return 0;
}