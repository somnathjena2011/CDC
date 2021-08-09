#include<bits/stdc++.h>
using namespace std;
int main()
{
	int V,E,i,j,u,v,w;
	cin>>V>>E;
	vector<pair<int,int>> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int s;
	cin>>s;
	int dist[V],parent[V],found[V];
	for(i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		parent[i]=-1;
		found[i]=0;
	}
	dist[0]=0;
	int mini;int vnear;
	for(i=1;i<=V;i++)
	{
		mini=INT_MAX;
		for(j=0;j<V;j++)
		{
			if(!found[j]&&dist[j]<mini)
			{
				mini=dist[j];
				vnear=j;
			}
		}
		found[vnear]=1;
		for(auto p:adj[vnear])
		{
			v=p.first;
			w=p.second;
			if(dist[vnear]!=INT_MAX&&dist[vnear]+w<dist[v])
			{
				dist[v]=dist[vnear]+w;
				parent[v]=vnear;
			}
		}
	}
	stack<int> path;
	for(i=0;i<V;i++)
	{
		j=i;
		path.push(j);
		while(parent[j]!=-1)
		{
			path.push(parent[j]);
			j=parent[j];
		}
		cout<<i<<"="<<dist[i]<<'\n';
		while(!path.empty())
		{
			j=path.top();
			path.pop();
			if(!path.empty())
				cout<<j<<"->";
			else
				cout<<j;
		}
		cout<<'\n';
	}
	return 0;
}