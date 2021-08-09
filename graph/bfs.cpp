#include<bits/stdc++.h>
using namespace std;
void BFS(vector<int> adj[],int* visited,queue<int>& q,int key)
{
	if(q.empty())
	{
		cout<<"Not Found\n";
		return;
	}
	int u =q.front();
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
	BFS(adj,visited,q,key);
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
	queue<int> q;
	q.push(1);
	visited[1]=1;
	BFS(adj,visited,q,key);
	return 0;
}