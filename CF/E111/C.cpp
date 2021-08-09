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
ll a[200005];
int main()
{
	ll t,n,i,j,ans,l,p,q,r,s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>a[i];
		ans=n;
		if(n>=2)
			ans+=(n-1);
		for(i=0;i<=n-3;i++)
		{
			if(a[i]<a[i+1]&&a[i+2]<a[i+1])
				++ans;
			else if(a[i]>a[i+1]&&a[i+1]<a[i+2])
				++ans;
		}
		for(i=0;i<=n-4;i++)
		{
			p=a[i];q=a[i+1];r=a[i+2];s=a[i+3];
			if(p<q&&r<p&&(s<q&&s>r))
				++ans;
			else if(p>q&&r>p&&(s>q&&s<r))
				++ans;
		}
		cout<<ans<<'\n';
	}
	return 0;
}