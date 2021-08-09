#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int s,int* visited)
{
	visited[s]=1;
	for(auto v:adj[s])
	{
		if(!visited[v])
			dfs(adj,v,visited);
	}
}
int main()
{
	int n,e,i,u,v;
	cin>>n>>e;
	vector<int> adj[n];
	for(i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		//adj[v].push_back(u);
	}
	int visited[n]={0};
	int last=0;
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		{
			dfs(adj,i,visited);
			last=i;
		}
	}
	for(i=0;i<n;i++)
		visited[i]=0;
	dfs(adj,last,visited);
	int co=0;
	for(i=0;i<n;i++)
	{
		if(visited[i])
			++co;
	}
	if(co==n)
		cout<<last<<'\n';
	else
		cout<<-1<<'\n';
	return 0;
}