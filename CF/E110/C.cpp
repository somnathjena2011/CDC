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
int dp0[200005],dp1[200005];
int main()
{
	ll t,i,j,n,ans;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		n=s.size();
		dp0[0]=s[0]=='?'||s[0]=='0'?1:0;
		dp1[0]=s[0]=='?'||s[0]=='1'?1:0;
		for(i=1;i<n;i++)
		{
			if(s[i]=='0')
				dp1[i]=0;
			else
				dp1[i]=dp0[i-1]+1;
			if(s[i]=='1')
				dp0[i]=0;
			else
				dp0[i]=dp1[i-1]+1;
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			ans+=max(dp1[i],dp0[i]);
		}
		cout<<ans<<'\n';
	}
	return 0;
}