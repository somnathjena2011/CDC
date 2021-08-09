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
int q[100005],a[100005];
int main()
{
	int m,n,i;
	cin>>m;
	int dis=100005;
	loop0(i,m)
	{
		cin>>q[i];
		dis=min(dis,q[i]);
	}
	cin>>n;
	loop0(i,n)
	cin>>a[i];
	sort(a,a+n,greater<int>());
	int ans=0;
	loop0(i,n)
	{
		if((i%(dis+2))<dis)
			ans+=a[i];
	}
	cout<<ans<<'\n';
	return 0;
}