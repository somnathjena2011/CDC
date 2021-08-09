/*
******************TRAVELLING SALESMAN PROBLEM********************
Given a grid of size n*m of characters 
*=> house
#=>blockade
.=>vacant street
Currently saleman at 0,0
Can move to only adjacent cells that share an edge

Determine the minimum distance to be moved to visit all the houses
and return back to 0,0

PART1:
Caluculate minimum distance from each house to every other house+initial position
Time=> O((no of houses+1)*size of grid)
PART2:
BITMASKING & DP
dp[i][mask]=minimum distance to go from house i to 0,0
            where next house is one of the house, the index for which
            mask bit is 1
Time=>O((n^2)*(2^n)) => 2^n possible mask values, n houses
                        To compute each value in dp
                        we iterate over all n bit positions in mask
                        This is done at most once due to memorization
n=No of houses
Overall time complexity= O(h*n*m)+O((h^2)*(2^h))
*/
#include<bits/stdc++.h>
using namespace std;
int diri[4]={0,-1,0,1};
int dirj[4]={-1,0,1,0};
int isValid(int i,int j,int n,int m,
	vector<vector<int>>& vis,string grid[])
{
	return (i>=0&&j>=0&&i<n&&j<m&&!vis[i][j])&&
	       (grid[i][j]!='#');
}
void bfs(string grid[],vector<vector<int>>& vis,vector<vector<int>> &dist,
	int i,int j,int n,int m)
{
	queue<pair<pair<int,int>,int>> qu;
	qu.push({{i,j},0});
	vis[i][j]=1;
	int p,q,x,y,d,w,v;
	while(!qu.empty())
	{
		p=qu.front().first.first;
		q=qu.front().first.second;
		w=qu.front().second;
		qu.pop();
		dist[p][q]=w;
		for(d=0;d<4;d++)
		{
			x=p+diri[d];
			y=q+dirj[d];
			if(isValid(x,y,n,m,vis,grid))
			{
				vis[x][y]=1;
				qu.push({{x,y},1+w});
			}
		}
	}
}
int solve(vector<vector<int>>& dist,vector<vector<int>>& dp,int i,int mask,int h)
{
	if(mask==0)
		return dist[i][0];
	if(i>h)
		return INT_MAX;
	if(dp[i][mask]!=-1)
		return dp[i][mask];
	int j;
	int ans=INT_MAX;int res;
	for(j=1;j<=h;j++)
	{
		if(mask&(1<<(j-1)))
		{
			res=solve(dist,dp,j,mask^(1<<(j-1)),h);
			if(res<INT_MAX&&dist[i][j]<INT_MAX)
				ans=min(ans,dist[i][j]+res);
		}
	}
	return dp[i][mask]=ans;
}
int main()
{
	int n,m,i,j,k;
	cin>>n>>m;
	string grid[n];
	vector<pair<int,int>> houses;
	houses.push_back({0,0});
	for(i=0;i<n;i++)
	{
		cin>>grid[i];
		for(j=0;j<m;j++)
		{
			if(grid[i][j]=='*')
				houses.push_back({i,j});
		}
	}
	int h=houses.size()-1;
	vector<vector<int>> dist(h+1,vector<int>(h+1,INT_MAX));
	vector<vector<int>> vis(n,vector<int>(m,0));
	vector<vector<int>> mdist(n,vector<int>(m,INT_MAX));
	for(i=0;i<=h;i++)
	{
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				vis[j][k]=0,mdist[j][k]=INT_MAX;
		bfs(grid,vis,mdist,houses[i].first,houses[i].second,n,m);
		for(j=0;j<=h;j++)
			dist[i][j]=mdist[houses[j].first][houses[j].second];
	}
	vector<vector<int>> dp(h+1,vector<int>(1<<h,-1));
	int ans=solve(dist,dp,0,(1<<h)-1,h);
	cout<<ans<<'\n';
	return 0;
}