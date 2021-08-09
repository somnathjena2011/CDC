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
int main()
{
	ll t;
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);  
	vector<vector<ll>> dp(5001,vector<ll>(5001,0));
	ll i,j,s,n,k,x,y,z,a,b,c;
	for(i=1;i<=5000;i++)
		dp[i][0]=INT_MAX;
	for(i=1;i<=5000;i++)
		dp[i][1]=i;
	for(i=1;i<=5000;i++)
	{
		for(j=2;j<=5000;j++)
		{
			if(j>i)
				dp[i][j]=INT_MAX;
			else if(j==i)
				dp[i][j]=INT_MAX;
			else
			{
				x=j;y=j-1;z=j-2;
				a=dp[i-j][j];
				if(j-1>=0)
					b=j-1>0?dp[i-j][j-1]:INT_MAX;
				else
					b=INT_MAX;
				if(j-2>=0)
					c=j-2>0?dp[i-j][j-2]:INT_MAX;
				else
					c=INT_MAX;
				dp[i][j]=min({a,b,c})+1;
			}
		}
	}
	cin>>t;
	while(t--)
	{
		cin>>s;x=INT_MAX;
		for(i=1;i<=s;i++)
			x=min(x,dp[s][i]);
		cout<<x<<'\n';
	}
	return 0;
}