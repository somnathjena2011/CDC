#include<bits/stdc++.h>
using namespace std;
bool negCycle(vector<vector<int>>& graph,int n)
{
	vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
	int i,j;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=graph[i][j];
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
					if(dp[i][i]<0)
						return true;
				}
			}
		}
	}
	return false;
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
	cout<<negCycle(graph,n)<<'\n';
	return 0;
}