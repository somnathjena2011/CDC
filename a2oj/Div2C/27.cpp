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
	int n;
	int i,j,k;
	vector<pair<int,int>> v;
	cin>>n;
	loop0(i,n)
	{
		cin>>j>>k;
		v.pb(mp(j,k));
	}
	sort(v.begin(),v.end());
	if(n==1)
		cout<<0<<'\n';
	else
	{
		int s=v[0].ff;int e=v[0].ss;int ans=0;
		for(i=1;i<n;i++)
		{
			if(v[i].ff>s&&v[i].ss<e)
				++ans;
			else
			{
				s=v[i].ff;
				e=v[i].ss;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}