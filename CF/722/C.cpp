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
ll l[200005],r[200005],visited[200005];
void dfs(vector<ll> adj[],ll s,ll& ans,ll prev)
{
	ll x;
	for(auto v:adj[s])
	{
		if(!visited[v])
		{
			visited[v]=1;
			if(abs(r[v]-prev)>abs(l[v]-prev))
			{
				ans+=abs(r[v]-prev);
				dfs(adj,v,ans,r[v]);
			}
			else
			{
				ans+=abs(l[v]-prev);
				dfs(adj,v,ans,l[v]);
			}
		}
	}
}
int main()
{
	ll t,n,u,v,i,j,mn,mx,mini,maxi,ans1,ans2,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop1(i,n)
		cin>>l[i]>>r[i];
		vector<ll> adj[n+1];
		loop1(i,n-1)
		{
			cin>>u>>v;
			adj[u].pb(v);adj[v].pb(u);
		}
		mn=l[1];mini=1;mx=r[1];maxi=1;
		for(i=2;i<=n;i++)
		{
			if(l[i]<mn)
			{
				mn=l[i];
				mini=i; 
			}
			if(r[i]>mx)
			{
				mx=r[i];
				maxi=i;
			}
		}
		loop1(i,n)
		visited[i]=0;
		ans1=ans2=ans=0;visited[mini]=1;
		dfs(adj,mini,ans1,mn);
		loop1(i,n)
		visited[i]=0;
		visited[maxi]=1;
		dfs(adj,maxi,ans2,mx);
		if(ans1>ans2)
			ans=ans1;
		else
			ans=ans2;
		cout<<ans<<'\n';
	}
	return 0;
}