#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],int* visited,int s,int key)
{
	visited[s]=1;
	cout<<s<<' ';
	if(s==key)
		return true;
	for(int v:adj[s])
	{
		if(!visited[v])
		{
			if(dfs(adj,visited,v,key))
				return true;
		}
	}
	return false;
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
	int key;
	cin>>key;
	int visited[n]={0};
	bool found=dfs(adj,visited,0,key);
	cout<<'\n';
	cout<<found<<'\n';
	return 0;
}