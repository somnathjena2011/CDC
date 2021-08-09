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
ll diri[8]={-1,-1,-1,0,1,1,1,0};
ll dirj[8]={-1,0,1,1,1,0,-1,-1};
int bfs(pair<ll,ll> sp,pair<ll,ll> ep,map<pair<ll,ll>,ll>& mp,map<pair<ll,ll>,ll>& visited)
{
	queue<pair<pair<ll,ll>,int>> q;
	q.push({sp,0});
	visited[sp]=1;
	pair<ll,ll> p;ll i,j,x,y,d;
	while(!q.empty())
	{
		p=q.front().first;
		d=q.front().second;
		q.pop();
		for(i=0;i<8;i++)
		{
			x=p.ff+diri[i];
			y=p.ss+dirj[i];
			if(mp[{x,y}]&&!visited[{x,y}])
			{
				if(x==ep.ff&&y==ep.ss)
					return d+1;
				visited[{x,y}]=1;
				q.push({{x,y},d+1});
			}
		}
	}
	return -1;
}
int main()
{
	ll x0,y0,x1,y1,n,r,a,b,i,j;
	map<pair<ll,ll>,ll> mp,visited;
	cin>>x0>>y0>>x1>>y1;
	cin>>n;
	loop0(i,n)
	{
		cin>>r>>a>>b;
		for(j=a;j<=b;j++)
			mp[{r,j}]=1;
	}
	ll ans=bfs({x0,y0},{x1,y1},mp,visited);
	cout<<ans<<'\n';
	return 0;
}