#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> floyd(vector<vector<int>>& graph,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
	vector<vector<int>> next(n,vector<int>(n,-1));
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dp[i][j]=graph[i][j];
			if(graph[i][j]>=0)
				next[i][j]=j;
		}
	}
	int k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[i][k]!=INT_MAX&&dp[k][j]!=INT_MAX
					&&dp[i][k]+dp[k][j]<dp[i][j])
				{
					dp[i][j]=dp[i][k]+dp[k][j];
					next[i][j]=next[i][k];
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			cout<<dp[i][j]<<' ';
		cout<<'\n';
	}
	return next;
}
void print(vector<vector<int>>& next,int i,int j)
{
	int u=i;int v=j;
	if(next[u][v]==-1)
	{
		cout<<'\n';
		return;
	}
	cout<<u<<' ';
	while(u!=v)
	{
		u=next[u][v];
		cout<<u<<' ';
	}
	cout<<'\n';
}
int main()
{
	int n,e,u,v,w;
	cin>>n>>e;
	vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
	while(e--)
	{
		cin>>u>>v>>w;
		graph[u][v]=w;
	}
	int i;
	for(i=0;i<n;i++)
		graph[i][i]=0;
	vector<vector<int>> next=floyd(graph,n);
	cin>>n;
	while(n--)
	{
		cin>>u>>v;
		print(next,u,v);
	}
	return 0;
}