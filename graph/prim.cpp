#include<bits/stdc++.h>
using namespace std;
int main()
{
	int v,e,i,j,x,y,w,u;
	cin>>v>>e;
	vector<pair<int,int>> adj[v];
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		adj[x].push_back({y,w});
		adj[y].push_back({x,w});
	}
	int dist[v],parent[v],found[v];
	for(i=0;i<v;i++)
	{
		dist[i]=INT_MAX;
		parent[i]=-1;
		found[i]=0;
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
	dist[0]=0;
	parent[0]=0;
	pq.push({0,0});
	pair<int,int> p;
	int minWt=0;
	while(!pq.empty())
	{
		p=pq.top();
		pq.pop();
		if(found[p.second])
			continue;
		u=p.second;
		w=p.first;
		minWt+=w;
		found[u]=1;
		for(auto q:adj[u])
		{
			x=q.first;
			y=q.second;
			if(!found[x]&&y<dist[x])
			{
				dist[x]=y;
				parent[x]=u;
				pq.push({y,x});
			}
		}
	}
	cout<<"Min. weight="<<minWt<<'\n';
	cout<<"Edges:\n";
	for(i=1;i<v;i++)
	{
		cout<<parent[i]<<"--"<<i<<'\n';
	}
	return 0;
}