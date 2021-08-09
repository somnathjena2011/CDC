#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],int* visited,int s,int key)
{
	if(s==key)
		return true;
	visited[s]=1;
	stack<int> st;
	st.push(s);
	int u;
	while(!st.empty())
	{
		u=st.top();
		cout<<u<<' ';
		st.pop();
		for(int v:adj[u])
		{
			if(v==key)
				return true;
			if(!visited[v])
			{
				visited[v]=true;
				st.push(v);
			}
		}
	}
	//cout<<'\n';
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