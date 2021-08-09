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
ull gcd(ull a,ull b)
{
	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{
	ll t;
	ull n,i,j,a,b,y,z,l;
	ull ans=0;
	cin>>t;
	vector<ull> odds={3,4,5,7,8,9,11,13,16,17,19,23,25,27,29,31,32,37,41,43,47};
	while(t--)
	{
		cin>>n;
		ans=(((n+1)/2)%mod*2)%mod;
		l=2;
		for(ll x:odds)
		{
			a=l;
			b=x*(l/gcd(x,l));
			l=b;
			ans=(ans+(((n/a-n/b)%mod)*(x%mod))%mod)%mod;
		}
		cout<<ans<<'\n';
	}
	return 0;
}