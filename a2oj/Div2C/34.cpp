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
int a[100005];
int pre[100005];
int main()
{
	int n,i,j;
	cin>>n;
	loop0(i,n)
	cin>>a[i];
	pre[0]=a[0];
	for(i=1;i<n;i++)
		pre[i]=pre[i-1]+a[i];
	int ans=0;
	for(i=0;i<n-1;i++)
	{
		if(pre[i]==pre[n-1]-pre[i])
			++ans;
	}
	cout<<ans<<'\n';
	return 0;
}