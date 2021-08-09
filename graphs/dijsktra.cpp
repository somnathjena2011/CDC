// #include<bits/stdc++.h>
// using namespace std;
// #define pii pair<int,int>
// int main()
// {
// 	int n,e,i,u,v,w;
// 	cin>>n>>e;
// 	vector<pii> adj[n];
// 	for(i=0;i<e;i++)
// 	{
// 		cin>>u>>v>>w;
// 		adj[u].push_back({v,w});
// 		adj[v].push_back({u,w});
// 	}
// 	int dist[n];
// 	for(i=0;i<n;i++)
// 		dist[i]=INT_MAX;
// 	int found[n]={0};
// 	priority_queue<pii,vector<pii>,greater<pii>> pq;
// 	int s;
// 	cin>>s;
// 	dist[s]=0;
// 	pq.push({0,s});
// 	while(!pq.empty())
// 	{
// 		w=pq.top().first;
// 		u=pq.top().second;
// 		pq.pop();
// 		if(found[u])
// 			continue;
// 		for(auto pr:adj[u])
// 		{
// 			if(dist[u]+pr.second<dist[pr.first])
// 			{
// 				dist[pr.first]=dist[u]+pr.second;
// 				pq.push({dist[pr.first],pr.first});
// 			}
// 		}
// 		found[u]=1;
// 	}
// 	for(i=0;i<n;i++)
// 		cout<<dist[i]<<' ';
// 	cout<<'\n';
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int main()
{
	int n,e,u,v,w,s;
	cin>>n>>e;
	vector<pii> adj[n];
	while(e--)
	{
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	cin>>s;
	vector<int> dist(n,INT_MAX);
	vector<int> found(n,0);
	priority_queue<pii,vector<pii>,greater<pii>> pq;
	dist[s]=0;
	pq.push({0,s});
	while(!pq.empty())
	{
		u=pq.top().second;
		w=pq.top().first;
		pq.pop();
		if(found[u])
			continue;
		found[u]=1;
		for(pii pr:adj[u])
		{
			v=pr.first;
			w=pr.second;
			if(!found[v]&&dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				pq.push({dist[v],v});
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<dist[i]<<' ';
	cout<<'\n';
	return 0;
}