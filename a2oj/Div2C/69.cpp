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
	string s;
	cin>>s;
	ll n=s.size();
	ll a=power(2,n-1);
	ll b=0;
	ll i;
	ll j=0;ll d=0;
	for(i=n-1;i>=0;i--)
	{
		d=s[i]-'0';
		b=(b+(d*power(2,j))%mod)%mod;
		j++;
	}
	ll ans=(a*b)%mod;
	cout<<ans<<'\n';
	return 0;
}