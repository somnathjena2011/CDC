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
ll pow(ll x,ll y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x%mod;
	ll m=y/2;
	ll p=pow(x,m)%mod;
	if(y%2==0)
		return (p*p)%mod;
	else
		return (((p*p)%mod)*x)%mod;
}
int main()
{
	ll n,m,k;
	cin>>n>>m>>k;
	ll x=(ll)(ceil((float)m/(k-1)));
	ll y=m+x-1;
	ll sum=0;
	ll n2,m2;
	if(y<=n)
		cout<<m<<'\n';
	else
	{
		ll ans=0;
		ll i;
		i=1;
		while(1)
		{
			n2=n-i*k;
			m2=m-i*k;
			x=(ll)(ceil((float)m2/(k-1)));
			y=m2+x-1;
			if(y<=n2)
			{
				sum=((2*((ll)pow(2,i)-1))%mod*k)%mod;
				ans=(sum+m2)%mod;
				cout<<ans<<'\n';
				break;
			}
			i++;
		}
	}
	return 0;
}