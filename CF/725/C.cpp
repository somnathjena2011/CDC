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
ll a[200005];
ll s1(ll k,ll s,ll e)
{
	ll m;
	ll ans=-1;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(a[m]>=k)
		{
			ans=m;
			e=m-1;
		}
		else
			s=m+1;
	}
	return ans;
}
ll s2(ll k,ll s,ll e)
{
	ll m;
	ll ans=-1;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(a[m]<=k)
		{
			ans=m;
			s=m+1;
		}
		else
			e=m-1;
	}
	return ans;
}
int main()
{
	ll t,n,l,r,i,j,x,y,m,ans;
	cin>>t;
	while(t--)
	{
		cin>>n>>l>>r;
		loop0(i,n)
		cin>>a[i];
		if(n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		if(n==2)
		{
			if(a[0]+a[1]>=l&&a[0]+a[1]<=r)
				cout<<1<<'\n';
			else
				cout<<0<<'\n';
			continue;
		}
		sort(a,a+n);ans=0;
		for(i=0;i<n-1;i++)
		{
			x=s1(l-a[i],i+1,n-1);
			y=s2(r-a[i],i+1,n-1);
			if(x==-1||y==-1)
				continue;
			else if(x>y)
				continue;
			else
				ans+=(y-x+1);
		}
		cout<<ans<<'\n';
	}
	return 0;
}