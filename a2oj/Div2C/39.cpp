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
ll lcm(ll a,ll b)
{
	return (a*b)/__gcd(a,b);
}
int main()
{
	ll n;
	cin>>n;
	if(n==1)
		cout<<1<<'\n';
	else if(n==2)
		cout<<2<<'\n';
	else if(n==3)
		cout<<6<<'\n';
	else if(n==4)
		cout<<12<<'\n';
	else
	{
		ll ans;
		if(n%2==1)
		{
			ans=lcm(lcm(n,n-1),n-2);
		}
		else 
		{
			ans=lcm(lcm(n-1,n-2),n-3);
			ans=max(ans,lcm(lcm(n,n-1),n-3));
		}
		cout<<ans<<'\n';
	}
	return 0;
}