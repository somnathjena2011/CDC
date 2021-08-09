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
ll nanosec(ll h,ll m,ll s)
{
	ll s1=h;
	ll s2=m/12;
	ll s3=s/720;

	ll hh1=s1/(3600);
	ll mm1=hh1*60+s2/(60);
	ll ss1=mm1*60+s3;
	s2=(360*hh1*120)/12+s2;
	s3=(360*mm1*120)/720+s3;
	//cout<<"ns1="<<ns1<<" ns2="<<ns2<<" ns3="<<ns3<<'\n';
	if(s1==s2&&s2==s3)
		return s1;
	else
		return -1;
}
int main()
{
	ll a,b,c,h,m,s,ns,t;
	cin>>t;
	ll x;
	ll a1,a2,a3;
	ll d1,d2,d3;
	ll dd1,dd2,dd3;
	float tick=(float)1/120;
	ll i=0;
	ll ans;
	loop1(x,t)
	{
		cin>>a>>b>>c;
		a=a/1e9;
		b=b/1e9;
		c=c/1e9;
		a1=a/120;
		a2=b/120;
		a3=c/120;
		//cout<<a1<<' '<<a2<<' '<<a3<<'\n';
		for(i=0;i<43200;i++)
		{
			d1=(a+i)%43200;
			d2=(b+i)%43200;
			d3=(c+i)%43200;
			dd1=d1/120;
			dd2=d2/120;
			dd3=d3/120;
			if((ans=nanosec(d1,d2,d3))>=0)
			{
				cout<<"Case #"<<x<<": "<<(ll)(dd1/30)<<' '<<(ll)(dd2/6)<<' '<<(ll)(dd3/6)<<' '<<0<<'\n';
				break;
			}
			else if((ans=nanosec(d1,d3,d2))>=0)
			{
				cout<<"Case #"<<x<<": "<<(ll)(dd1/30)<<' '<<(ll)(dd3/6)<<' '<<(ll)(dd2/6)<<' '<<0<<'\n';
				break;
			}
			else if((ans=nanosec(d2,d1,d3))>=0)
			{
				cout<<"Case #"<<x<<": "<<(ll)(dd2/30)<<' '<<(ll)(dd1/6)<<' '<<(ll)(dd3/6)<<' '<<0<<'\n';
				break;
			}
			else if((ans=nanosec(d2,d3,d1))>=0)
			{
				cout<<"Case #"<<x<<": "<<(ll)(dd2/30)<<' '<<(ll)(dd3/6)<<' '<<(ll)(dd1/6)<<' '<<0<<'\n';
				break;
			}
			else if((ans=nanosec(d3,d1,d2))>=0)
			{
				cout<<"Case #"<<x<<": "<<(ll)(dd3/30)<<' '<<(ll)(dd1/6)<<' '<<(ll)(dd2/6)<<' '<<0<<'\n';
				break;
			}
			else if((ans=nanosec(d3,d2,d1))>=0)
			{
				cout<<"Case #"<<x<<": "<<(ll)(dd3/30)<<' '<<(ll)(dd2/6)<<' '<<(ll)(dd1/6)<<' '<<0<<'\n';
				break;
			}
		}
	}
	return 0;
}