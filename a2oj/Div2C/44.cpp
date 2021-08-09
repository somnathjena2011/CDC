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
ll gcd(ll a,ll b,ll *x,ll *y)
{
	if(b==0)
	{
		*x=1;*y=0;
		return a;
	}
	ll x1,y1;
	ll g = gcd(b,a%b,&x1,&y1);
	*x = y1;
	*y = x1-(a/b)*y1;
	return g;
}
ll modInv(ll a)
{
	ll x,y,g;
	g = gcd(a,mod,&x,&y);
	if(g!=1)
		return 0;
	else
	{
		x=(x+mod)%mod;
		return x;
	}
}
int main()
{
	ll a,b,n;
	cin>>a>>b>>n;
	ll x,y,c,d;
	ll ans=0;
	ll i,j;
	ll maxi=b*n;
	ll dig=(ll)ceil(log10(maxi));
	queue<ll> q;
	q.push(0);
	ll m;
	ll s,t,u;
	ll sum1,sum2;
	ll fact[n+1];
	fact[0]=fact[1]=1;
	for(i=2;i<=n;i++)
		fact[i]=(fact[i-1]*i)%mod;
	ll fn=fact[n];
	for(i=1;i<=dig;i++)
	{
		m=q.size();
		while(m--)
		{
			u=q.front();
			q.pop();
			sum1=u*10+a;
			sum2=u*10+b;
			q.push(sum1);
			q.push(sum2);
			y=(sum1-a*n)/(b-a);
			x=(sum1-b*n)/(a-b);
			if(x>=0&&y>=0&&x+y==n&&a*x+b*y==sum1)
			{
				s=modInv(fact[x]);
				t=modInv(fact[y]);
				ans=(ans+(((fact[n]*s)%mod)*t)%mod)%mod;
			}
			y=(sum2-a*n)/(b-a);
			x=(sum2-b*n)/(a-b);
			if(x>=0&&y>=0&&x+y==n&&a*x+b*y==sum2)
			{
				s=modInv(fact[x]);
				t=modInv(fact[y]);
				ans=(ans+(((fact[n]*s)%mod)*t)%mod)%mod;
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}