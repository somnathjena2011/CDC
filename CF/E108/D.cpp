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
ull a[5002],b[5002];
int main()
{
	ll n,i,j,k,l,m;
	cin>>n;
	loop0(i,n)
	cin>>a[i];
	loop0(i,n)
	cin>>b[i];
	ull pre[n];
	ull post[n];
	pre[0]=a[0]*b[0];
	for(i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i]*b[i];
	post[n-1]=a[n-1]*b[n-1];
	for(i=n-2;i>=0;i--)
		post[i]=post[i+1]+a[i]*b[i];
	ull dp[n][n];
	loop0(i,n)
	{
		loop0(j,n)
		dp[i][j]=0;
	}
	loop0(i,n)
	dp[i][i]=a[i]*b[i];
	for(i=0;i<n-1;i++)
	{
		dp[i][i+1]=a[i+1]*b[i]+a[i]*b[i+1];
	}
	for(k=2;k<n;k++)
	{
		for(i=0;i<n-k;i++)
		{
			dp[i][i+k]=dp[i+1][i+k-1]+a[i]*b[i+k]+a[i+k]*b[i];
		}
	}
	ull ans=0;ull left=0;ull right=0;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n-k;i++)
		{
			if(i==0)
				left=0;
			else
				left=pre[i-1];
			j=i+k;
			if(j==n-1)
				right=0;
			else
				right=post[j+1];
			//cout<<"i="<<i<<" j="<<j<<'\n';
			//cout<<left<<' '<<dp[i][j]<<' '<<right<<'\n';
			if(left+right+dp[i][j]>ans)
				ans=left+right+dp[i][j];
		}
	}
	cout<<ans<<'\n';
	return 0;
}