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
int init[100005];
int tar[100005];
void dfs(vector<int> adj[],int s,int p,int odd,int even,int level,int& ans,vector<int>& res)
{
	int val;
	if(level%2==1)
		val=init[s]^odd;
	else
		val=init[s]^even;
	int od=odd;int ev=even;
	if(val!=tar[s])
	{
		++ans;
		if(level%2==1)
			od=odd^1;
		else
			ev=even^1;
		res.pb(s);
	}
	for(auto v:adj[s])
	{
		if(v!=p)
			dfs(adj,v,s,od,ev,level^1,ans,res);
	}
}
int main()
{
	int n,i,j,u,v;
	cin>>n;
	vector<int> adj[n+1];
	loop0(i,n-1)
	{
		cin>>u>>v;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	loop1(i,n)
	cin>>init[i];
	loop1(i,n)
	cin>>tar[i];
	int odd=0;
	int even=0;
	vector<int> res;int ans=0;
	dfs(adj,1,-1,odd,even,1,ans,res);
	cout<<ans<<'\n';
	for(auto v:res)
		cout<<v<<'\n';
	return 0;
}