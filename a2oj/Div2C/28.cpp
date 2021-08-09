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
vector<int> adj[100005];
long cost[100005];
int n,m;
void SCCUtil(int u,int* disc,int* low,int* inStack,stack<int>& st,vector<vector<int>>& ans)
{
	static int time=0;
	disc[u]=low[u]=++time;
	st.push(u);
	inStack[u]=1;int v;
	for(auto it=adj[u].begin();it!=adj[u].end();it++)
	{
		v=*it;
		if(!disc[v])
		{
			SCCUtil(v,disc,low,inStack,st,ans);
			low[u]=min(low[u],low[v]);
		} 
		else if(inStack[v])
			low[u]=min(low[u],disc[v]);
	}
	int w=0;
	if(low[u]==disc[u])
	{
		vector<int> scc;
		while(st.top()!=u)
		{
			w=st.top();
			scc.pb(w);
			inStack[w]=0;
			st.pop();
		}
		w=st.top();
		scc.pb(w);
		inStack[w]=0;
		st.pop();
		ans.pb(scc);
	}
}
void SCC(vector<vector<int>>& ans)
{
	int disc[n+1]={0};
	int low[n+1]={0};
	int inStack[n+1]={0};
	stack<int> st;
	for(int i=1;i<=n;i++)
		if(disc[i]==0)
			SCCUtil(i,disc,low,inStack,st,ans);
}
int main()
{
	int i,u,v;
	cin>>n;
	loop1(i,n)
	cin>>cost[i];
	cin>>m;
	loop0(i,m)
	{
		cin>>u>>v;
		adj[u].pb(v);
	}
	vector<vector<int>> ans;
	SCC(ans);
	long nos;long sum=0;long mini=1e18;long pro=1;
	for(auto scc:ans)
	{
		mini=LONG_MAX;
		for(auto ind:scc)
		{
			if(cost[ind]<mini)
				mini=cost[ind];
		}
		sum+=mini;nos=0;
		for(auto ind:scc)
		{
			if(cost[ind]==mini)
				++nos;
		}
		pro=((pro%mod)*(nos%mod))%mod;
	}
	cout<<sum<<' '<<pro<<'\n';
	return 0;
}