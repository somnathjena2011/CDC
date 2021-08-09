#include<bits/stdc++.h>
using namespace std;
void bfs(vector<int> adj[],int* visited,queue<int>& q)
{
	if(q.empty())
	{
		cout<<'\n';
		return;
	}
	int u=q.front();
	cout<<u<<' ';
	q.pop();
	for(int v:adj[u])
	{
		if(!visited[v])
		{
			visited[v]=1;
			q.push(v);
		}
	}
	bfs(adj,visited,q);
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
	queue<int> q;
	q.push(s);
	visited[s]=1;
	bfs(adj,visited,q);
	return 0;
}