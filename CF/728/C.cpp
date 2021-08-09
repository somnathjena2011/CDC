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
ll d[100005];
int main()
{
	ll t,n,i,j,ans,sub;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(i=0;i<n;i++)
			cin>>d[i];
		sort(d,d+n);
		ans=0;sub=0;
		for(i=1;i<n;i++)
		{
			ans+=(d[i]-d[i-1]);
			sub+=(i*(d[i]-d[i-1]));
			ans-=sub;
		}
		cout<<ans<<'\n';
	}
	return 0;
}