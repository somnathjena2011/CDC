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
double solve(double c,double m,double p,double v,ll t)
{
	if(c<0.000001&&m<0.000001)
		return p*t;
	if(c<0.000001)
	{
		if(m<=v)
			return m*solve(0,0,1,v,t+1)+p*t;
		else
			return m*solve(0,m-v,p+v,v,t+1)+p*t;
	}
	if(m<0.000001)
	{
		if(c<=v)
			return c*solve(0,0,1,v,t+1)+p*t;
		else
			return c*solve(0,m-v,p+v,v,t+1)+p*t;
	}
	double ans=p*t;
	if(c<=v)
		ans+=c*solve(0,m+c/2,p+c/2,v,t+1);
	else
		ans+=c*solve(c-v,m+v/2,p+v/2,v,t+1);
	if(m<=v)
		ans+=m*solve(c+m/2,0,p+m/2,v,t+1);
	else
		ans+=m*solve(c+v/2,m-v,p+v/2,v,t+1);	
	return ans;
}
int main()
{
	ll t;
	double c,m,p,v,ans,n;
	cin>>t;
	while(t--)
	{
		cin>>c>>m>>p>>v;
		cout<<solve(c,m,p,v,1)<<'\n';
	}
	return 0;
}