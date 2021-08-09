// #include<bits/stdc++.h>
// using namespace std;
// void topo_all(vector<int> adj[],vector<int>& sort,int n,int *indegree,int* visited)
// {
// 	bool flag=true;
// 	for(int i=0;i<n;i++)
// 	{
// 		if(!visited[i]&&!indegree[i])
// 		{
// 			flag=false;
// 			sort.push_back(i);
// 			visited[i]=1;
// 			for(int v:adj[i])
// 				--indegree[v];
// 			topo_all(adj,sort,n,indegree,visited);
// 			sort.pop_back();
// 			visited[i]=0;
// 			for(int v:adj[i])
// 				++indegree[v];
// 		}
// 	}
// 	if(flag)
// 	{
// 		for(int v:sort)
// 			cout<<v<<' ';
// 		cout<<'\n';
// 	}
// }
// int main()
// {
// 	int n,e,i,u,v;
// 	cin>>n>>e;
// 	vector<int> adj[n];
// 	int indegree[n]={0};
// 	for(i=0;i<e;i++)
// 	{
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		++indegree[v];
// 	}
// 	vector<int> sort;
// 	int visited[n]={0};
// 	topo_all(adj,sort,n,indegree,visited);
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
void topo(vector<int> adj[],vector<int>& sort,
	vector<int>& visited,vector<int>& indegree,int n)
{
	bool flag=true;
	for(int i=0;i<n;i++)
	{
		if(!visited[i]&&!indegree[i])
		{
			flag=false;
			visited[i]=1;
			sort.push_back(i);
			for(int v:adj[i])
				--indegree[v];
			topo(adj,sort,visited,indegree,n);
			sort.pop_back();
			for(int v:adj[i])
				++indegree[v];
			visited[i]=0;
		}
	}
	if(flag)
	{
		for(int v:sort)
			cout<<v<<' ';
		cout<<'\n';
	}
}
int main()
{
	int n,e,u,v;
	cin>>n>>e;
	vector<int> adj[n];
	vector<int> indegree(n,0);
	vector<int> visited(n,0);
	while(e--)
	{
		cin>>u>>v;
		++indegree[v];
		adj[u].push_back(v);
	}
	vector<int> sort;
	topo(adj,sort,visited,indegree,n);
	return 0;
}