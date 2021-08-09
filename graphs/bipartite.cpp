// #include<bits/stdc++.h>
// using namespace std;
// bool twoColor(vector<int> adj[],int s,int* colors)
// {
// 	queue<int> q;
// 	q.push(s);
// 	colors[s]=0;int u;
// 	while(!q.empty())
// 	{
// 		u=q.front();
// 		q.pop();
// 		for(int v:adj[u])
// 		{
// 			if(colors[v]==-1)
// 			{
// 				q.push(v);
// 				colors[v]=1-colors[u];
// 			}
// 			else if(colors[v]==colors[u])
// 				return false;
// 		}
// 	}
// 	return true;
// }
// int main()
// {
// 	int n,e,i,u,v;
// 	cin>>n>>e;
// 	vector<int> adj[n];
// 	int colors[n];
// 	for(i=0;i<n;i++)
// 		colors[i]=-1;
// 	for(i=0;i<e;i++)
// 	{
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 		adj[v].push_back(u);
// 	}
// 	bool bi=true;
// 	for(i=0;i<n;i++)
// 	{
// 		if(colors[i]==-1)
// 		{
// 			bi=twoColor(adj,i,colors);
// 			if(!bi)
// 				break;
// 		}
// 	}
// 	if(!bi)
// 		cout<<"Not possibles\n";
// 	else
// 	{
// 		for(i=0;i<n;i++)
// 			cout<<colors[i]<<' ';
// 		cout<<'\n';
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
bool bfs(vector<int> adj[],vector<int>& color,int s)
{
	queue<int> q;
	q.push(s);
	int u;
	color[s]=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		for(int v:adj[u])
		{
			if(color[v]==color[u])
				return false;
			else if(color[v]==-1)
			{
				color[v]=1-color[u];
				q.push(v);
			}
		}
	}
	return true;
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<int> adj[n];
	int u,v;
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> color(n,-1);
	for(int i=0;i<n;i++)
	{
		if(color[i]==-1)
		{
			if(!bfs(adj,color,i))
			{
				cout<<"Not possible\n";
				return 0;
			}
		}
	}
	for(int i=0;i<n;i++)
		cout<<color[i]<<' ';
	cout<<'\n';
	return 0;
}