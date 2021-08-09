// #include<bits/stdc++.h>
// using namespace std;
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
// 	queue<int> q;
// 	for(i=0;i<n;i++)
// 	{
// 		if(!indegree[i])
// 			q.push(i);
// 	}
// 	v=0;
// 	while(!q.empty())
// 	{
// 		u=q.front();
// 		++v;
// 		cout<<u<<' ';
// 		q.pop();
// 		for(int w:adj[u])
// 		{
// 			--indegree[w];
// 			if(!indegree[w])
// 				q.push(w);
// 		}
// 	}
// 	cout<<'\n';
// 	if(v!=n)
// 		cout<<"Not possible\n";
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,e,u,v,i;
	cin>>n>>e;
	vector<int> adj[n];
	vector<int> degree(n,0);
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		++degree[v];
	}
	queue<int> q;
	for(i=0;i<n;i++)
		if(!degree[i])
			q.push(i);
	int c=0;
	while(!q.empty())
	{
		u=q.front();
		q.pop();
		c++;
		cout<<u<<' ';
		for(int vt:adj[u])
		{
			--degree[vt];
			if(!degree[vt])
				q.push(vt);
		}
	}
	cout<<'\n';
	if(c!=n)
		cout<<"Cycle\n";
	return 0;
}