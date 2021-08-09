//given a DAG, with some undirected edges between nodes
//assign directions to undirected edges so that graph remains DAG
#include<bits/stdc++.h>
using namespace std;
bool topo(vector<int> adj[],int n,int* indegree,vector<int>& sort)
{
	int i,u;
	queue<int> q;
	for(i=0;i<n;i++)
	{
		if(!indegree[i])
			q.push(i);
	}
	int c=0;
	while(!q.empty())
	{
		u=q.front();
		sort.push_back(u);
		q.pop();
		++c;
		for(int v:adj[u])
		{
			--indegree[v];
			if(!indegree[v])
				q.push(v);
		}
	}
	return (c==n);
}
int main()
{
	int n,de,ue,i,u,v;
	cin>>n>>de>>ue;
	vector<int> adj[n];
	int indegree[n]={0};
	for(i=0;i<de;i++)
	{
		cin>>u>>v;
		++indegree[v];
		adj[u].push_back(v);
	}
	vector<pair<int,int>> und(ue);
	for(i=0;i<ue;i++)
	{
		cin>>u>>v;
		und[i]={u,v};
	}
	vector<int> sort;
	bool tp=topo(adj,n,indegree,sort);
	if(tp)
	{
		int topind[n];
		for(i=0;i<n;i++)
			topind[sort[i]]=i;
		for(i=0;i<ue;i++)
		{
			u=und[i].first;
			v=und[i].second;
			if(topind[u]<topind[v])
				cout<<u<<"->"<<v<<'\n';
			else
				cout<<v<<"->"<<u<<'\n';
		}
	}
	return 0;
}