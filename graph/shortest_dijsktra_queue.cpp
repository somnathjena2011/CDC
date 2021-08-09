#include<bits/stdc++.h>
using namespace std;;
int main()
{
	int V,E;
	int i,u,v,w,j;
	cin>>V>>E;
	vector<pair<int,int>> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
	int found[V]={0};
	int vnear;
	int dist[V];int parent[V];
	for(i=0;i<V;i++)
	{
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	int s;
	cin>>s;
	dist[s]=0;
	pq.push({0,s});
	pair<int,int> p;
	for(i=1;i<=V;i++)
	{
		p=pq.top();
		pq.pop();
		vnear=p.second;
		found[vnear]=1;
		for(auto p:adj[vnear])
		{
			v=p.first;
			if(!found[v]&&dist[v]>dist[vnear]+p.second)
			{
				dist[v]=dist[vnear]+p.second;
				pq.push({dist[v],v});
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