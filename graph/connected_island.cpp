#include<bits/stdc++.h>
using namespace std;
int graph[1000][1000];
int visited[1000][1000];
int diri[8]={1,0,-1,-1,-1,0,1,1};
int dirj[8]={-1,-1,-1,0,1,1,1,0};
int isValid(int i,int j,int R,int C)
{
	if(i>=0&&j>=0&&i<R&&j<C&&graph[i][j]&&!visited[i][j])
		return 1;
	return 0;
}
void BFS(int x,int y,int R,int C)
{
	visited[x][y]=1;
	queue<pair<int,int>> q;
	q.push({x,y});
	int u,v,i,j;
	while(!q.empty())
	{
		u=q.front().first;
		v=q.front().second;
		q.pop();
		for(i=0;i<8;i++)
		{
			if(isValid(u+diri[i],v+dirj[i],R,C))
			{
				visited[u+diri[i]][v+dirj[i]]=1;
				q.push({u+diri[i],v+dirj[i]});
			}
		}
	}
}
int main()
{
	int R,C,i,j;
	cin>>R>>C;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			cin>>graph[i][j];
			visited[i][j]=0;
		}
	}
	int ans=0;
	for(i=0;i<R;i++)
	{
		for(j=0;j<C;j++)
		{
			if(graph[i][j]&&!visited[i][j])
			{
				++ans;
				BFS(i,j,R,C);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}