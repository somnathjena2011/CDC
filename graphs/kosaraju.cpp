// #include<bits/stdc++.h>
// using namespace std;
// void transpose(vector<int> adj[],vector<int> trans[],int n)
// {
// 	int i;
// 	for(i=0;i<n;i++)
// 	{
// 		for(int v:adj[i])
// 			trans[v].push_back(i);
// 	}
// }
// void dfs(vector<int> adj[],int s,int* visited,stack<int>& st)
// {
// 	for(int v:adj[s])
// 	{
// 		if(!visited[v])
// 		{
// 			visited[v]=1;
// 			dfs(adj,v,visited,st);
// 		}
// 	}
// 	st.push(s);
// }
// void SCC(vector<int> adj[],int n,vector<vector<int>>& SCCs)
// {
// 	int visited[n]={0};
// 	stack<int> st;
// 	int i;
// 	for(i=0;i<n;i++)
// 	{
// 		if(!visited[i])
// 		{
// 			visited[i]=1;
// 			dfs(adj,i,visited,st);
// 		}
// 	}
// 	vector<int> trans[n];
// 	transpose(adj,trans,n);
// 	for(i=0;i<n;i++)
// 		visited[i]=0;
// 	stack<int> st2;int u;
// 	while(!st.empty())
// 	{
// 		u=st.top();
// 		st.pop();
// 		if(visited[u])
// 			continue;
// 		vector<int> cc;
// 		st2.push(u);
// 		visited[u]=1;
// 		cc.push_back(u);
// 		while(!st2.empty())
// 		{
// 			u=st2.top();
// 			st2.pop();
// 			for(int v:trans[u])
// 			{
// 				if(!visited[v])
// 				{
// 					st2.push(v);
// 					visited[v]=1;
// 					cc.push_back(v);
// 				}
// 			}
// 		}
// 		SCCs.push_back(cc);
// 	}
// }
// int main()
// {
// 	int n,e,i,u,v;
// 	cin>>n>>e;
// 	vector<int> adj[n];
// 	for(i=0;i<n;i++)
// 	{
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		//adj[v].push_back(u);
// 	}
// 	vector<vector<int>> SCCs;
// 	SCC(adj,n,SCCs);
// 	for(auto vec:SCCs)
// 	{
// 		for(auto el:vec)
// 			cout<<el<<' ';
// 		cout<<'\n';
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
void transpose(vector<int> adj[],vector<int> trans[],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int v:adj[i])
			trans[v].push_back(i);
	}
}
void dfs(vector<int> adj[],stack<int>& st,vector<int>& visited,int s)
{
	visited[s]=1;
	for(int v:adj[s])
		if(!visited[v])
			dfs(adj,st,visited,v);
	st.push(s);
}
void SCC(vector<int> adj[],vector<vector<int>>& ans,vector<int>& visited,int s)
{
	stack<int> st;
	st.push(s);
	visited[s]=1;
	vector<int> cc;
	int u;
	while(!st.empty())
	{
		u=st.top();
		st.pop();
		cc.push_back(u);
		for(int v:adj[u])
		{
			if(!visited[v])
			{
				visited[v]=1;
				st.push(v);
			}
		}
	}
	ans.push_back(cc);
}
int main()
{
	int n,e,u,v,i;
	cin>>n>>e;
	vector<int> visited(n,0);
	stack<int> st;
	vector<int> adj[n];
	vector<int> trans[n];
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	for(i=0;i<n;i++)
		if(!visited[i])
			dfs(adj,st,visited,i);
	transpose(adj,trans,n);
	fill(visited.begin(),visited.end(),0);
	vector<vector<int>> ans;
	while(!st.empty())
	{
		u=st.top();
		st.pop();
		if(!visited[u])
			SCC(trans,ans,visited,u);
	}
	for(auto comp:ans)
	{
		for(auto vt:comp)
			cout<<vt<<' ';
		cout<<'\n';
	}
	return 0;
}