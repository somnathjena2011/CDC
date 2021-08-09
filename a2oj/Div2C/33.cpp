#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define rloop0(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>0;i--)
#define sloop0(i,n,s) for(i=0;i<n;i+=s)
int main()
{
	int n,m,x,y,i,j;
	cin>>n>>m>>x>>y;
	vector<string> grid;
	string s;
	loop0(i,n)
	{
		cin>>s;
		grid.pb(s);
	}
	int black[m+1]={0};
	int white[m+1]={0};
	int c=0;
	for(j=0;j<m;j++)
	{
		c=0;
		for(i=0;i<n;i++)
		{
			if(grid[i][j]=='#')
				++black[j+1];
			else
				++white[j+1];
		}
	}
	int preb[m+1]={0};
	int prew[m+1]={0};
	loop1(j,m)
	{
		preb[j]=preb[j-1]+black[j];
		prew[j]=prew[j-1]+white[j];
	}
	int dpw[m+1]={0};
	int dpb[m+1]={0};
	int minb,minw;
	for(j=1;j<x;j++)
	{
		dpw[j]=INT_MAX;
		dpb[j]=INT_MAX;
	}
	dpw[x]=preb[x];
	dpb[x]=prew[x];
	for(j=x+1;j<=m;j++)
	{
		minb=minw=INT_MAX;
		//cout<<"j="<<j<<'\n';
		for(i=j-y;i<=j-x;i++)
		{
			if(i<0)
				continue;
			//cout<<"i="<<i<<'\n';
			//cout<<"dpw="<<dpw[i]<<" dpb="<<dpb[i]<<" prewj="<<prew[j]<<" prewi="<<prew[i]<<" prebj="<<preb[j]<<" prebi="<<preb[i]<<'\n';
			if(dpw[i]!=INT_MAX)
			minb=min(minb,dpw[i]+prew[j]-prew[i]);
			if(dpb[i]!=INT_MAX)
			minw=min(minw,dpb[i]+preb[j]-preb[i]);
			//cout<<minb<<' '<<minw<<'\n';
		}
		dpw[j]=minw;
		dpb[j]=minb;
	}
	cout<<min(dpw[m],dpb[m])<<'\n';
	return 0;
}