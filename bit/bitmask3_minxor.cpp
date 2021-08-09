/*
***************MINIMUM XOR SUM PERMUTATION******************
Given 2 arrays A & B
Permute array B such that A[0]^B[0]+A[1]^B[1]+....A[n-1]^B[n-1] is minimized
Both A & B are of size n

n<=14
SOLUTION=> BITMASKING
dp[i][mask] = minimum xor sum obtained from A[0]....A[i]
              considering elements of B where the indices are those
              that are 1 in mask
Time Complexity=> O((n^2)*(2^n))
*/
#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>& dp,int i,int mask,int a[],int b[],int n)
{
	if(i<0)
		return 0;
	if(dp[i][mask]!=-1)
		return dp[i][mask];
	int ans=INT_MAX;
	for(int j=0;j<n;j++)
	{
		if(mask&(1<<j))
		{
			ans=min(ans,(a[i]^b[j])+solve(dp,i-1,mask^(1<<j),a,b,n));
		}
	}
	return dp[i][mask]=ans;
}
int main()
{
	int n,i,j;
	cin>>n;
	int a[n],b[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
		cin>>b[i];
	vector<vector<int>> dp(n,vector<int>((1<<n),-1));
	int ans=solve(dp,n-1,(1<<n)-1,a,b,n);
	cout<<ans<<'\n';
	return 0;
}