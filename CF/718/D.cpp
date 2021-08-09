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
int a[502][502];
int b[502][502];
int dp[502][502][25];
int diri[4] = {-1,0,1,0};
int dirj[4] = {0,1,0,-1};
int isAdjacent(pair<int,int> p1,pair<int,int> p2)
{
	int x1=p1.ff;int y1=p1.ss;
	int x2=p2.ff;int y2=p2.ss;
	if(x1==x2&&y2==y1+1)
		return a[x1][y1];
	else if(x1==x2&&y1==y2+1)
		return a[x1][y2];
	else if(y1==y2&&x2==x1+1)
		return b[x1][y1];
	else if(y1==y2&&x1==x2+1)
		return b[x2][y1];
	else
		return 0;
}
int isValid(int i,int j,int n,int m,int ox,int oy,int kk)
{
	if(i<=0||j<=0||i>n||j>m)
		return 0;
	else if(abs(i-ox)+abs(j-oy)>kk/2)
	{
		//cout<<i<<","<<j<<" "<<ox<<","<<oy<<" "<<kk<<'\n';
		return 0;
	}
	return 1;
}
int bfs(pair<int,int> from,pair<int,int> to,pair<int,int> origin,int n,int kk,int nn,int mm)
{
	int minWt = INT_MAX;
	int wt=0;int w=0;
	if(n==0)
	{
		if(from.ff==to.ff&&from.ss==to.ss)
			return 0;
		else
			return INT_MAX;
	}
	else if(n==1)
	{
		if((wt=isAdjacent(from,to))!=0)
			return wt;
		else
			return INT_MAX;
	}
	else
	{
		int i;
		for(i=0;i<4;i++)
		{
			int x1=from.ff+diri[i];
			int y1=from.ss+dirj[i];
			wt=0;
			if(isValid(x1,y1,nn,mm,origin.ff,origin.ss,kk)&&(wt=isAdjacent(from,mp(x1,y1))))
			{
				w=bfs(mp(x1,y1),to,origin,n-1,kk,nn,mm);
				if(w!=INT_MAX)
					minWt=min(minWt,wt+w);
			}			
		}
		return minWt;
	}
}
int main()
{
	int n,m,k,i,j,l;
	cin>>n>>m>>k;int ans;
	for(i=1;i<=n;i++)
		for(j=1;j<m;j++)
			cin>>a[i][j];
	for(i=1;i<n;i++)
		for(j=1;j<=m;j++)
			cin>>b[i][j];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			for(l=0;l<=k;l++)
				dp[i][j][l]=0;
	if(k%2==1)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				cout<<-1<<' ';
			cout<<'\n';
		}
	}
	else
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
			{
				ans=bfs(mp(i,j),mp(i,j),mp(i,j),k,k,n,m);
				if(ans==INT_MAX)
					cout<<-1<<' ';
				else
					cout<<ans<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}