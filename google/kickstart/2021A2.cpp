#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll g[305][305];
ll visited[305][305];
ll ans;
ll diri[4]={0,-1,0,1};
ll dirj[4]={-1,0,1,0};
ll isValid(ll i,ll j,ll r,ll c)
{
	return i>=0&&i<r&&j>=0&&j<c&&!visited[i][j];
}
int main()
{
	ll t,i,j,r,c,x,i1,j1,u,v,h1,h2,no;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>r>>c;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				cin>>g[i][j];
				visited[i][j]=0;
			}
		}
		ans=0;
		priority_queue<pair<int,pair<int,int>>> pq;
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				pq.push({g[i][j],{i,j}});
			}
		}
		no=0;
		pair<int,pair<int,int>> p;
		while(no<r*c)
		{
			p=pq.top();
			h1=p.first;
			i1=p.second.first;
			j1=p.second.second;
			pq.pop();
			if(visited[i1][j1])
				continue;
			visited[i1][j1]=1;
			++no;
			for(i=0;i<4;i++)
			{
				u=i1+diri[i];
				v=j1+dirj[i];
				if(isValid(u,v,r,c))
				{
					h2=g[u][v];
					if(h2<h1-1)
					{
						ans+=((h1-1)-h2);
						g[u][v]=h1-1;
						pq.push({g[u][v],{u,v}});
					}
				}
			}
		}
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}