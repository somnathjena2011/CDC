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
ll a[100005];
ll pre[100005];
ll search(ll ss,ll ee,ll n,ll k)
{
	ll s=ss;
	ll e=ee;
	ll m;
	ll ans=n;
	ll sum=0;
	ll sub=0;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(m==0)
			sub=pre[n];
		else
			sub=pre[n]-pre[m-1];
		sum=(n-m+1)*a[n]-sub;
		if(sum<=k)
		{
			ans=m;
			e=m-1;
		}
		else
			s=m+1;
	}
	return ans;
}
int main()
{
	ll n,k;
	cin>>n>>k;
	ll i,j;
	loop0(i,n)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	loop0(i,n)
	{
		if(i==0)
			pre[i]=a[i];
		else
			pre[i]=a[i]+pre[i-1];
	}
	ll ans=1;ll num=a[0];
	for(i=1;i<n;i++)
	{
		j=search(0,i-1,i,k);
		if(j<=i&&j>= 0&&i-j+1>ans)
		{
			ans=i-j+1;
			num=a[i];
		}
	}
	cout<<ans<<' '<<num<<'\n';
	return 0;
}