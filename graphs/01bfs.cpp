#include<bits/stdc++.h>
using namespace std;
void bfs01(vector<pair<int,int>> adj[],int* dist,int s)
{
	deque<int> q;
	q.push_back(s);
	dist[s]=0;
	while(!q.empty())
	{
		s=q.front();
		q.pop_front();
		for(auto v:adj[s])
		{
			if(dist[s]+v.second<dist[v.first])
			{
				dist[v.first]=dist[s]+v.second;
				if(v.second==0)
					q.push_front(v.first);
				else
					q.push_back(v.first);
			}
		}
	}
}
int main()
{
	int n,e,u,v,w;
	cin>>n>>e;
	vector<pair<int,int>> adj[n];
	for(int i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int dist[n];
	for(int i=0;i<n;i++)
		dist[i]=INT_MAX;
	int s;
	cin>>s;
	bfs01(adj,dist,s);
	for(int i=0;i<n;i++)
		cout<<dist[i]<<' ';
	cout<<'\n';
	return 0;
}