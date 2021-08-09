#include<bits/stdc++.h>
using namespace std;
bool detect(vector<vector<int>>& graph)
{
	int n=graph.size();
	vector<vector<int>> dp(n,vector<int>(n,0));
	int i,j,k;
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			dp[i][j]=graph[i][j];
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(dp[i][k]!=INT_MAX&&dp[k][j]!=INT_MAX
					&&dp[i][k]+dp[k][j]<dp[i][j])
					dp[i][j]=dp[i][k]+dp[k][j];
			}
			if(dp[i][i]<0)
				return true;
		}
	}
	return false;
}
int main()
{
	int n,e,u,v,w,i,j;
	cin>>n>>e;
	vector<vector<int>> graph(n,vector<int>(n,INT_MAX));
	while(e--)
	{
		cin>>u>>v>>w;
		graph[u][v]=w;
	}
	for(i=0;i<n;i++)
		graph[i][i]=0;
	cout<<detect(graph)<<'\n';
	return 0;
}