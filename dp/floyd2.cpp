#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> floyd(vector<vector<int>>& graph)
{
	int n=graph.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	vector<vector<int>> next(n,vector<int>(n,-1));
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			dp[i][j]=graph[i][j];
			if(graph[i][j]!=INT_MAX)
				next[i][j]=j;
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[i][k]!=INT_MAX&&dp[k][j]!=INT_MAX)
				{
					if(dp[i][k]+dp[k][j]<dp[i][j])
					{
						dp[i][j]=dp[i][k]+dp[k][j];
						next[i][j]=next[i][k];
					}
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
void print(vector<vector<int>>& next,int u,int v)
{
	if(next[u][v]<0)
	{
		cout<<'\n';
		return;
	}
	int i=u;
	cout<<i<<' ';
	while(i!=v)
	{
		i=next[i][v];
		cout<<i<<' ';
	}
	cout<<'\n';
}
int main()
{
	int n,e;
	cin>>n>>e;
	int i,j;
	vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
	int u,v,w;
	while(e--)
	{
		cin>>u>>v>>w;
		graph[u][v]=w;
	}
	for(i=0;i<n;i++)
		graph[i][i]=0;
	vector<vector<int>> next=floyd(graph);
	cin>>n;
	while(n--)
	{
		cin>>u>>v;
		print(next,u,v);
	}
	return 0;
}