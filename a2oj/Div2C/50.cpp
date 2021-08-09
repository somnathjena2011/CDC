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
ll cnt[36005];
int main()
{
	ll a;string s;
	cin>>a; 
	cin>>s;
	ll n=s.size();
	ll i,j;
	for(i=0;i<=n*9;i++)
		cnt[i]=0;
	ll pre[n];pre[0]=s[0]-'0'; 
	for(i=1;i<n;i++)
		pre[i]=pre[i-1]+(s[i]-'0');
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(i==0)
				++cnt[pre[j]];
			else
				++cnt[pre[j]-pre[i-1]];
		}
	}
	ll ans=0;ll x;
	for(i=0;i<=n*9;i++)
	{
		if(i==0&&a==0)
			ans+=(cnt[0]*((n*(n+1))/2));
		else if(i==0)
			continue;
		else
		{
			if(a%i==0)
			{
				x=a/i;
				if(x<=n*9)
				ans+=(cnt[i]*cnt[x]);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
}