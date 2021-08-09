#include<bits/stdc++.h>
using namespace std;
void BFS(vector<pair<int,int>> adj[],int s,int* dist)
{
	int u;
	deque<int> dq;
	dq.push_front(s);
	dist[s]=0;
	while(!dq.empty())
	{
		u=dq.front();
		dq.pop_front();
		for(auto v:adj[u])
		{
			if(dist[u]+v.second<dist[v.first])
			{
				dist[v.first]=dist[u]+v.second;
				if(v.second==0)
					dq.push_front(v.first);
				else
					dq.push_back(v.first);
			}
		}
	}
}
int main()
{
	int V,E;
	cin>>V>>E;
	vector<pair<int,int>> adj[V];
	int i,u,v,w;
	for(i=0;i<E;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int s;
	cin>>s;
	int dist[V];
	for(i=0;i<V;i++)
		dist[i]=INT_MAX;
	cout<<'\n';
	BFS(adj,s,dist);
	for(i=0;i<V;i++)
		cout<<dist[i]<<' ';
	cout<<'\n';
	return 0;
}