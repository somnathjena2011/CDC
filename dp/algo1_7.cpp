#include<bits/stdc++.h>
using namespace std;
int solve(int n,int k)
{
	int dp[n+1][k+1];
	int i,j;
	dp[0][0]=0;
	for(j=1;j<=k;j++)
		dp[0][j]=INT_MAX;
	for(i=1;i<=n;i++)
		dp[i][0]=0;
	for(i=1;i<=n;i++)
		dp[i][1]=1;
	int l;
	for(i=1;i<=n;i++)
	{
		for(j=2;j<=k;j++)
		{
			dp[i][j]=INT_MAX;
			for(l=1;l<=j;l++)
			{
				if(dp[i-1][l-1]!=INT_MAX&&dp[i][j-l]!=INT_MAX)
					dp[i][j]=min(dp[i][j],1+max(dp[i-1][l-1],dp[i][j-l]));
			}
		}
	}
	return dp[n][k];
}
int main()
{
	FILE* fin=fopen("input.txt","r");
	FILE* fout=fopen("output.txt","w");
	int t,n,k;
	fscanf(fin,"%d",&t);
	while(t--)
	{
		fscanf(fin,"%d %d",&n,&k);
		fprintf(fout,"%d %d %d\n",n,k,solve(n,k));
	}
	fclose(fin);
	fclose(fout);
}