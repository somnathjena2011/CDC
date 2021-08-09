#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
map<ll,ll> mp;
ll primes(ll n)
{
	if(mp.find(n)!=mp.end())
		return mp[n];
	ll ans=0;ll x=n;
	while(n%2==0)
	{
		n/=2;
		++ans;
	}
	for(ll i=3;i*i<=n;i+=2)
	{
		while(n%i==0)
		{
			n/=i;
			++ans;
		}
	}
	if(n>2)
		++ans;
	return mp[x]=ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
    //mp.clear();
	ll t,a,b,k,g,x,y,px,py,i,j,l,m,mi,mj,p,q;
	cin>>t;
	while(t--)
	{
		cin>>a>>b>>k;
		if(a==b)
		{
			l=primes(a);
			mi=l==0?0:1;
			mi=2*mi;
			m=2*l;
			//cout<<"l="<<l<<" mi="<<mi<<" m="<<m<<'\n';
			if(k>=mi&&k<=m)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
		else
		{
			g=__gcd(a,b);
			//x=a/g;y=b/g;
			//px=primes(x);py=primes(y);
			//i=px==0?0:1;
			//j=py==0?0:1;
			if(g==a||g==b)
				p=1;
			else
				p=2;
			q=primes(a)+primes(b);
			if(k>=p&&k<=q)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}