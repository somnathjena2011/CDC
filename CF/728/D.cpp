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
void add(ll n1,ll d1,ll n2,ll d2,ll &x,ll &y)
{
	ll n=n1*d2+n2*d1;
	ll d=d1*d2; 
	ll g=__gcd(abs(n),d);
	n/=g;
	d/=d;
	x=n;y=d;
}
bool check(ll n1,ll d1,ll n2, ll d2)
{
	ll a1=n1*d2;
	ll a2=n2*d1;
	return a1>=a2;
}
bool compare(ll a1,ll a2,ll b,ll z)
{
	ll n1=a1;ll d1=1;ll n2=a2;ll d2=1;
	ll ch=1;ll x,y,u,v;ll g,p,q,r,s;
	cout<<a1<<' '<<a2<<' '<<b<<'\n';
	while(ch)
	{
		x=n1;y=d1;u=n2;v=d2;
		add(x,y,u,v,n1,d1);
		add(n1,d1,-b,1,n1,d1);
		add(x,y,u,v,n2,d2);
		add(n2,d2,b,1,n2,d2);
		d1*=2;d2*=2;
		g=__gcd(abs(n1),d1);
		n1/=g;d1/=g;
		g=__gcd(abs(n2),d2);
		n2/=g;d2/=g;
		cout<<n1<<"/"<<d1<<' '<<n2<<"/"<<d2<<'\n';
		if(!check(x,y,n1,d1))
		{
			n1=x;d1=y;
		}
		if(!check(n2,d2,u,v))
		{
			n2=u;d2=v;
		}
		if(x==n1&&y==d1)
			break;
	}
	cout<<"a1="<<a1<<" a2="<<a2<<" b="<<b<<'\n';
	cout<<n1<<"/"<<d1<<' '<<n2<<"/"<<d2<<'\n';
	cout<<check(n1,d1,z,1)<<'\n';
	return check(n1,d1,z,1);
}
int main()
{
	ll n,i,j,q,x;
	cin>>n;
	ll b[n],c[n];
	for(i=0;i<n;i++)
		cin>>c[i];
	for(i=0;i<n-1;i++)
		cin>>b[i];
	cin>>q;
	cin>>x;
	ll pro=1;
	for(i=2;i<n;i++)
		pro=(pro*(c[i]+1))%mod;
	ll ans=0;
	for(i=0;i<=c[0];i++)
	{
		for(j=0;j<=c[1];j++)
		{
			if(compare(i,j,b[0],x))
				ans=(ans+pro)%mod;
		}
	}
	cout<<ans<<'\n';
	return 0;
}