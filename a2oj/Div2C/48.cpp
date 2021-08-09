#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll> rotate(ll x,ll y,ll a,ll b,ll times)
{
	if(times==0)
		return {x,y};
	ll u,v;
	u=a+b-y;
	v=x-a+b;
	return rotate(u,v,a,b,times-1);
}
bool isSquare(ll x[],ll y[])
{
	vector<ll> dist;
	ll i,j,d;
	for(i=0;i<3;i++)
	{
		for(j=i+1;j<4;j++)
		{
			d=(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
			dist.push_back(d);
		}
	}
	sort(dist.begin(),dist.end());
	if(dist[0]==dist[1]&&dist[1]==dist[2]&&dist[2]==dist[3]&&dist[4]==dist[5]&&dist[4]>dist[0])
		return true;
	return false;
}
int main()
{
	ll n,i,j,k,l;
	ll a[4],b[4],x[4],y[4];
	ll newx[4],newy[4];
	pair<ll,ll> p;
	ll rot;ll ans;
	cin>>n;
	while(n--)
	{
		for(i=0;i<4;i++)
			cin>>x[i]>>y[i]>>a[i]>>b[i];
		ans=INT_MAX;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				for(k=0;k<4;k++)
				{
					for(l=0;l<4;l++)
					{
						p=rotate(x[0],y[0],a[0],b[0],i);
						newx[0]=p.first;newy[0]=p.second;
						p=rotate(x[1],y[1],a[1],b[1],j);
						newx[1]=p.first;newy[1]=p.second;
						p=rotate(x[2],y[2],a[2],b[2],k);
						newx[2]=p.first;newy[2]=p.second;
						p=rotate(x[3],y[3],a[3],b[3],l);
						newx[3]=p.first;newy[3]=p.second;
						rot=i+j+k+l;
						if(isSquare(newx,newy)&&rot<ans)
							ans=rot;
					}
				}
			}
		}
		if(ans==INT_MAX)
			cout<<-1<<'\n';
		else
			cout<<ans<<'\n';
	}
	return 0;
}