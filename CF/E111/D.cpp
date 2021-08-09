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
ll ar[200005];
pair<ll,ll> search(ll a,ll l,ll r)
{
	ll mi=r;ll ma=l;
	ll s=l;ll e=r;ll m;
	ll b=a+1;
	ll req=2*a+1;
	ll n;
	while(s<=e)
	{
		m=s+(e-s)/2;
		n=req-m;
		if(n>r)
			s=m+1;
		else if(n<l)
			e=m-1;
		else
		{
			mi=m;
			e=m-1;
		}
	}
	while(s<=e)
	{
		m=s+(e-s)/2;
		n=req-m;
		if(n>r)
			s=m+1;
		else if(n<l)
			e=m-1;
		else
		{
			ma=m;
			s=m+1;
		}
	}
	return {mi,ma};
}
int main()
{
	ll t,n,l,r,i,j,x,y,z,a,b,c,d,e,f,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		for(i=1;i<n;i++)
		{
			pair<ll,ll> p=search(i,l,r);
			x=p.first;
			y=p.second;
			e=y-x;
			c=x-l;
			d=r-y;
			a=min(c,d);
			b=max(c,d);
			z=((b*e)%mod+(a*(a+1))%mod+(2*a*(b-a))%mod+(((b-a)*(b-a+1))/2)%mod)%mod;
			ar[i]=z;
		}
		ans=1;
		for(i=1;i<n;i++)
			ans=(ans*ar[i])%mod;
		cout<<ans<<'\n';
	}
	return 0;
}