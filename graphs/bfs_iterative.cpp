#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int *visited,int s)
{
	queue<int> q;
	q.push(s);
	visited[s]=1;
	int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		cout<<u<<' ';
		for(int v:adj[u])
		{
			if(!visited[v])
			{
				visited[v]=1;
				q.push(v);
			}
		}
	}
	cout<<'\n';
}
int main()
{
	int n,e,u,v;
	cin>>n>>e;
	vector<int> adj[n];
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int s;
	cin>>s;
	int visited[n]={0};
	bfs(adj,visited,s);
	return 0;
}