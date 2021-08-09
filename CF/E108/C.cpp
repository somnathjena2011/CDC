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
ll u[200005];
ll s[200005];
bool compare(ll a,ll b){
	if(a>=b)
		return true;
	return false;
}
int main()
{
	ll t,i,j,n,k,ans,l,m,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop1(i,n)
		{	
			cin>>u[i];
		}
		loop1(i,n)
		cin>>s[i];
		vector<vector<ll>> univ(n+1);
		loop1(i,n)
		{
			univ[u[i]].pb(s[i]);
		}
		loop1(i,n)
		{
			if(univ[i].size()>0)
			sort(univ[i].begin(),univ[i].end(),compare);
		}
		vector<vector<ll>> univ2;
		loop1(i,n)
		{
			if(univ[i].size()>0)
				univ2.pb(univ[i]);
		}
		ans=0;
		l=univ2.size();
		m=0;
		loop0(i,l)
		{
			if(univ2[i].size()>m)
				m=univ2[i].size();
			for(j=1;j<univ2[i].size();j++)
			{
				univ2[i][j]=univ2[i][j-1]+univ2[i][j];	
			}
		}
		loop1(i,n)
		{
			ans=0;
			if(i<=m)
			{
				for(auto v:univ2)
				{
					l=v.size();
					if(i<=l)
					{
						x=(l/i)*i-1;
						if(x>=0&&x<l)
						ans+=v[x];
					}
				}
			}
			cout<<ans<<' ';
		}
		cout<<'\n';
	}
	return 0;
}