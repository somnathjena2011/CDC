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
ll l[200005],r[200005];
ll dpl[200005],dpr[200005];
void solve(vector<ll> adj[],ll root,ll parent)
{
	for(auto v:adj[root])
	{
		if(v!=parent)
		{
			solve(adj,v,root);
			dpl[root]+=max(abs(l[root]-l[v])+dpl[v],abs(l[root]-r[v])+dpr[v]);
			dpr[root]+=max(abs(r[root]-l[v])+dpl[v],abs(r[root]-r[v])+dpr[v]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
	ll t,n,u,v,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> adj[n+1];
		dpl[0]=dpr[0]=0;
		loop1(i,n)
		{
			cin>>l[i]>>r[i];
			dpl[i]=dpr[i]=0;
		}
		loop0(i,n-1)
		{
			cin>>u>>v;
			adj[u].pb(v);
			adj[v].pb(u);
		}
		solve(adj,1,0);
		cout<<max(dpl[1],dpr[1])<<'\n';
	}
	return 0;
}