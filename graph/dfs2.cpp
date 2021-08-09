#include<bits/stdc++.h>
using namespace std;
bool dfs(vector<int> adj[],int* visited,int s,int key)
{
	stack<int> st;
	st.push(s);
	visited[s]=1;
	int u;
	while(!st.empty())
	{
		u=st.top();
		st.pop();
		//visited[u]=1;
		cout<<u<<' ';
		if(u==key)
			return true;
		for(auto v:adj[u])
		{
			if(!visited[v])
			{
				visited[v]=1;
				st.push(v);
			}
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
	bool found=dfs(adj,visited,1,key);
	if(found)
		cout<<"Found\n";
	else
		cout<<"Not Found\n";
	return 0;
}