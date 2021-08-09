#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
ll g[3][3];
ll replace(ll x)
{
	ll ans=0;
	if(x-g[0][0]==g[2][2]-x)
		++ans;
	if(x-g[2][0]==g[0][2]-x)
		++ans;
	if(x-g[0][1]==g[2][1]-x)
		++ans;
	if(x-g[1][0]==g[1][2]-x)
		++ans;
	return ans;
}
int main()
{
	ll t,i,j,x,ans;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>g[0][0]>>g[0][1]>>g[0][2];
		cin>>g[1][0]>>g[1][2];
		cin>>g[2][0]>>g[2][1]>>g[2][2];
		ans=0;
		if(g[0][1]-g[0][0]==g[0][2]-g[0][1])
			++ans;
		if(g[2][1]-g[2][0]==g[2][2]-g[2][1])
			++ans;
		if(g[1][0]-g[0][0]==g[2][0]-g[1][0])
			++ans;
		if(g[1][2]-g[0][2]==g[2][2]-g[1][2])
			++ans;
		ll a=(g[1][0]+g[1][2])/2;
		ll b=(g[0][1]+g[2][1])/2;
		ll c=(g[0][0]+g[2][2])/2;
		ll d=(g[0][2]+g[2][0])/2;
		j=0;
		j=max(j,replace(a));
		j=max(j,replace(b));
		j=max(j,replace(c));
		j=max(j,replace(d));
		ans+=j;
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}
