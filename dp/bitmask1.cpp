#include<bits/stdc++.h>
using namespace std;
bool isin(vector<int> capList[],int person,int cap)
{
	for(int c:capList[person])
		if(c==cap)
			return true;
	return false;
}
int solve(vector<int> capList[],vector<vector<int>>& dp,
	int mask,int cap,int persons,int caps)
{
	if(mask==0)
		return 1;
	if(cap>caps)
		return 0;
	if(dp[mask][cap]>=0)
		return dp[mask][cap];
	int ways=solve(capList,dp,mask,cap+1,persons,caps);
	int i;
	for(i=0;i<persons;i++)
	{
		if(mask&(1<<i)&&isin(capList,i,cap))
			ways+=solve(capList,dp,mask^(1<<i),cap+1,persons,caps);
	}
	return dp[mask][cap]=ways;
}
int main()
{
	int caps,persons,i,j,cap;
	cin>>caps>>persons;
	vector<int> capList[persons];
	for(i=0;i<persons;i++)
	{
		cin>>j;
		while(j--)
		{
			cin>>cap;
			capList[i].push_back(cap);
		}
	}
	int size=1<<persons;	vector<vector<int>> dp(size,vector<int>(caps+1,-1));
	int ans=solve(capList,dp,size-1,1,persons,caps);
	cout<<ans<<'\n';
	return 0;
}