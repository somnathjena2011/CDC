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
ll power(ll x,ll y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x%mod;
	if(x<=1)
		return x;
	ll p=power(x,y/2);
	if(y%2==0)
		return (p*p)%mod;
	else
		return (((x*p)%mod)*p)%mod;
}
int main()
{
	ll n,x,i;
	cin>>n>>x;
	vector<ll> a(n),b;
	ll sum=0;
	loop0(i,n)
	{
		cin>>a[i];
		sum+=a[i];
	}
	loop0(i,n)
	b.pb(sum-a[i]);
	sort(b.rbegin(),b.rend());
	ll v;ll cnt=0;
	while(1)
	{
		v=b[b.size()-1];
		cnt=0;
		while(b.size()>0&&b[b.size()-1]==v)
		{
			++cnt;
			b.pop_back();
		}
		if(cnt%x!=0)
		{
			v=min(v,sum);
			cout<<power(x,v)<<'\n';
			return 0;
		}
		else
		{
			cnt/=x;
			loop0(i,cnt)
			b.pb(v+1);
		}
	}
	return 0;
}