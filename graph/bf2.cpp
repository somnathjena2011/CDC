#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int> adj[],int V,int s,int key)
{
	int visited[V+1]={0};
	queue<int> q;
	visited[s]=1;
	q.push(s);int u;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		cout<<u<<' ';
		if(u==key)
		{
			cout<<"Found\n";
			return;
		}
		for(auto v:adj[u])
		{
			if(!visited[v])
			{
				visited[v]=1;
				q.push(v);
			}
		}
	}
	cout<<"Not Found\n";
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
	BFS(adj,V,1,key);
	return 0;
}