#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
//caps caps
//n persons with some caps out of those caps caps
//n<=10, caps<=100
int n,caps;
ll solve(vector<vector<ll>> &dp,vector<int> capList[],int mask,int i)
{
	if(mask==((1<<n)-1))
		return 1;
	if(i>caps)
		return 0;
	if(dp[mask][i]!=-1)
		return dp[mask][i];
	ll ways=solve(dp,capList,mask,i+1);
	int size=capList[i].size();int j;
	for(j=0;j<size;j++)
	{
		if(mask&(1<<capList[i][j]))
			continue;
		ways+= solve(dp,capList,(mask|(1<<capList[i][j])),i+1);
		ways%=mod;
	}
	return dp[mask][i]=ways;
}
int main()
{
	int cap,i,j,c;
	cin>>n>>caps;
	int maxMask = (1<<n)-1;
	vector<vector<ll>> dp(maxMask+1,vector<ll>(caps+1,-1));
	vector<int> capList[caps+1];
	for(i=0;i<n;i++)
	{
		cin>>cap;
		for(j=0;j<cap;j++)
		{
			cin>>c;
			capList[c].push_back(i);
		}
	}
	ll ans=solve(dp,capList,0,1);
	cout<<ans<<'\n';
	return 0;
}