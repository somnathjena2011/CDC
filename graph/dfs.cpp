#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],int s,int* visited,int key)
{
	visited[s]=1;
	cout<<s<<' ';
	if(s==key)
	{
		return true;
	}
	for(auto v:adj[s])
	{
		if(!visited[v])
		{
			if(dfs(adj,v,visited,key))
				return true;
		}
	}
	return false;
}
int main()
{
	int V,E;
	cin>>V>>E;
	vector<int> adj[V+1];
	int i,u,v;
	for(i=0;i<E;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int key;
	cin>>key;
	int visited[V+1]={0};
	bool found=dfs(adj,1,visited,key);
	if(found)
		cout<<"Found\n";
	else
		cout<<"Not Found\n";
	return 0;
}