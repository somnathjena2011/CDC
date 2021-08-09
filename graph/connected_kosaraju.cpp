#include<bits/stdc++.h>
using namespace std;
void dfs(vector<int> adj[],int s,int* visited,stack<int>& st)
{
	for(auto v:adj[s])
	{
		if(!visited[v])
		{
			visited[v]=1;
			dfs(adj,v,visited,st);
		}
	}
	st.push(s);
}
void transpose(vector<int> adj[],vector<int> trans[],int V)
{
	int i;
	for(i=0;i<V;i++)
	{
		for(auto v:adj[i])
			trans[v].push_back(i);
	}
}
void dfs2(vector<int> adj[],int s,int* visited)
{
	cout<<s<<' ';
	for(auto v:adj[s])
	{
		if(!visited[v])
		{
			visited[v]=1;
			dfs2(adj,v,visited);
		}
	}
}
void kosaraju(vector<int> adj[],int V)
{
	int visited[V]={0};
	int i;
	stack<int> s;
	for(i=0;i<V;i++)
	{
		if(!visited[i])
		{
			visited[i]=1;
			dfs(adj,i,visited,s);
		}
	}
	for(i=0;i<V;i++)
		visited[i]=0;
	vector<int> trans[V];
	transpose(adj,trans,V);
	while(!s.empty())
	{
		i=s.top();
		s.pop();
		if(!visited[i])
		{
			visited[i]=1;
			dfs2(trans,i,visited);
			cout<<'\n';
		}
	}
}
int main()
{
	int V,E;
	int u,v,i;
	cin>>V>>E;
	vector<int> adj[V];
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	kosaraju(adj,V);
}