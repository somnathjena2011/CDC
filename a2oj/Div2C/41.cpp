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
ll search(vector<ll>& a,ll n,ll k)
{
	ll s=0;
	ll e=n-1;
	ll m;
	ll ans=e;
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
	ll n,d,i,j;
	cin>>n>>d;
	vector<ll> a(n);
	loop0(i,n)
	{
		cin>>j;
		a[i]=j;
	}
	ll ans=0;
	ll m;
	loop0(i,n)
	{
		m=search(a,n,a[i]+d);
		if(m-i+1<3)
			continue;
		else
		{
			m=m-i;
			ans=ans+(m*(m-1))/2;
		}
	}
	cout<<ans<<'\n';
	return 0;
}