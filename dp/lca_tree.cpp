#include<bits/stdc++.h>
using namespace std;
int lg;int ti;
//run dfs to obtain 2^ith ancestors of all nodes and their depths
void dfs(vector<int> adj[],int s,int p,vector<vector<int>>& anc
	,int tin[],int tout[],int depth[],int d)
{
	++ti;
	tin[s]=ti;
	depth[s]=d;
	anc[s][0]=p;
	for(int i=1;i<=lg;i++)
		anc[s][i]=anc[anc[s][i-1]][i-1];
	for(int v:adj[s])
	{
		if(v!=p)
			dfs(adj,v,s,anc,tin,tout,depth,d+1);
	}
	++ti;
	tout[s]=ti;
}
//check if u is an ancestor of v
bool isAncestor(int u,int v,int tin[],int tout[])
{
	return (tin[u]<=tin[v]&&tout[u]>=tout[v]);
}
int query(int u,int v,vector<vector<int>>& anc,int tin[],
	int tout[],int depth[])
{
	if(isAncestor(u,v,tin,tout))
		return u;
	else if(isAncestor(v,u,tin,tout))
		return v;
	else
	{
		int a,b;
		if(depth[u]>=depth[v])
		{
			a=u;
			b=v;
		}
		else
		{
			a=v;
			b=u;
		}
		int diff=depth[a]-depth[b];
		int req=depth[b];
		int i;
		if(diff!=0)
		{
			for(i=lg;i>=0;i--)
			{
				if(depth[a]==req)
					break;
				if(depth[anc[a][i]]>=req)
					a=anc[a][i];
			}
		}
		for(i=lg;i>=0;i--)
		{
			if(!isAncestor(anc[a][i],b,tin,tout))
				a=anc[a][i];
		}
		return anc[a][0];
	}
}
int main()
{
	int n,i,u,v,q;
	cin>>n;
	vector<int> adj[n+1];int depth[n+1];int tin[n+1];int tout[n+1];
	ti=0;
	lg=(int)ceil(log2(n));
	vector<vector<int>> anc(n+1,vector<int>(lg+1,-1));
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs(adj,1,1,anc,tin,tout,depth,0);
	cin>>q;
	while(q--)
	{
		cin>>u>>v;
		cout<<query(u,v,anc,tin,tout,depth)<<'\n';
	}
	return 0;
}