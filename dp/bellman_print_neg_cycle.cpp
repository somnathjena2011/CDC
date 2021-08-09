#include<bits/stdc++.h>
using namespace std;
bool bellman(vector<vector<int>>& edges,int n,int s)
{
	int i;
	int dist[n];
	int parent[n];
	for(i=0;i<n;i++)
	{
		dist[i]=INT_MAX;
		parent[i]=-1;
	}
	dist[0]=0;
	int u,v,w;
	for(i=1;i<n;i++)
	{
		for(auto ed:edges)
		{
			u=ed[0];v=ed[1];w=ed[2];
			if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				parent[v]=u;
			}
		}
	}
	int c=-1;
	for(auto ed:edges)
	{
		u=ed[0];v=ed[1];w=ed[2];
		if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
		{
			c=v;
			break;
		}
	}
	if(c==-1)
	return false;
	for(i=0;i<n;i++)
	{
		if(parent[c]==-1)
			break;
		c=parent[c];
	}
	vector<int> cycle;
	for(int v=c;;v=parent[v])
	{
		cycle.push_back(v);
		if(v==c&&cycle.size()>1)
			break;
	}
	reverse(cycle.begin(),cycle.end());
	for(int v:cycle)
		cout<<v<<' ';
	cout<<'\n';
	return true;
}
int main()
{
	int n,e,i,u,v,w;
	cin>>n>>e;
	vector<vector<int>> edges(e);
	vector<int> ed(3);
	for(i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		ed[0]=u;ed[1]=v;ed[2]=w;
		edges[i]=ed;
	}
	int s;
	cin>>s;
	bool cycle=bellman(edges,n,s);
	if(!cycle)
		cout<<"No negative weight cycle\n";
	return 0;
}