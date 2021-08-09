#include<bits/stdc++.h>
using namespace std;
void BFS(vector<vector<int>>& SCCs,vector<int> adj[],int s,int* visited)
{
	vector<int> SCC;
	queue<int> q;
	q.push(s);
	visited[s]=1;
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		SCC.push_back(u);
		for(auto v:adj[u])
		{
			if(!visited[v])
			{
				visited[v]=1;
				q.push(v);
			}
		}
	}
	SCCs.push_back(SCC);
}
int main()
{
	int V,E;
	int i,u,v,w;
	cin>>V>>E;
	vector<int> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<vector<int>> SCCs;
	int visited[V]={0};
	for(i=0;i<V;i++)
	{
		if(!visited[i])
		BFS(SCCs,adj,i,visited);
	}
	for(auto ve:SCCs)
	{
		for(auto no:ve)
			cout<<no<<' ';
		cout<<'\n';
	}
	return 0;
}