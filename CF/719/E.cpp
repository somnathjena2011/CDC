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
int main()
{
	int t,i,n,m,l,j;
	cin>>t;
	string s;ll ans;ll ans2;
	while(t--)
	{
		cin>>n;
		cin>>s;
		ll pre[n]={0};
		ll post[n]={0};
		pre[0]=s[0]=='*'?1:0;
		post[n-1]=s[n-1]=='*'?1:0;
		for(i=1;i<n;i++)
		{
			if(s[i]=='*')
				pre[i]=pre[i-1]+1;
			else
				pre[i]=pre[i-1];
		}
		for(i=n-2;i>=0;i--)
		{
			if(s[i]=='*')
				post[i]=post[i+1]+1;
			else
				post[i]=post[i+1];
		}
		ans=0;
		for(i=0;i<n;i++)
		{
			if(s[i]=='.')
			{
				ans+=min(pre[i],post[i]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}