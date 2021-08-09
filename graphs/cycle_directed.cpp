#include<bits/stdc++.h>
using namespace std;
bool cycle(vector<int> adj[],int s,int* visited,int* onStack)
{
	visited[s]=1;
	onStack[s]=1;
	cout<<s<<' ';
	for(int v:adj[s])
	{
		if(onStack[v])
			return true;
		if(!visited[v])
		{
			if(cycle(adj,v,visited,onStack))
				return true;
		}
	}
	onStack[s]=0;
	return false;
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	int i,u,v;
	for(i=0;i<e;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	int visited[n]={0};
	int onStack[n]={0};
	for(i=0;i<n;i++)
	{
		if(!visited[i])
		{
			if(cycle(adj,i,visited,onStack))
			{
				cout<<'\n';
				cout<<"Found\n";
				return 0;
			}
			cout<<'\n';
		}
	}
	cout<<"Not Founrd\n";
	return 0;
}