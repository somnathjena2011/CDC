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
int adj[2005][2005];
int dist[2005];
int n;
void query(int i)
{
	cout<<"? "<<i<<'\n';
	cout.flush();
	loop1(i,n)
	cin>>dist[i];
}
int main()
{
	int i,j;
	cin>>n;
	loop1(i,n)
	{
		loop1(j,n)
		adj[i][j]=0;
	}
	set<int> o,e;
	query(1);
	for(i=2;i<=n;i++)
	{
		if(dist[i]&1)
			o.insert(i);
		else
			e.insert(i);
	}
	if(o.size()>e.size())
		o.swap(e);
	loop1(i,n)
	{
		if(dist[i]==1)
			adj[1][i]=adj[i][1]=1;
	}
	for(int u:o)
	{
		query(u);
		loop1(i,n)
		{
			if(dist[i]==1)
				adj[u][i]=adj[i][u]=1;
		}
	}
	cout<<"!\n";
	loop1(i,n-1)
	{
		for(j=i+1;j<=n;j++)
		{
			if(adj[i][j])
				cout<<i<<' '<<j<<'\n';
		}
	}
	return 0;
}