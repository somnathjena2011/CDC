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
ll a[100005];
ll incStart[100005];
ll decEnd[100005];
int main()
{
	ll n,m;
	cin>>n>>m;
	ll i,j,l,q,r;
	loop1(i,n)
	cin>>a[i];
	decEnd[1]=1;
	incStart[n]=1;
	for(i=2;i<=n;i++)
	{
		if(a[i]<=a[i-1])
			decEnd[i]=1+decEnd[i-1];
		else
			decEnd[i]=1;
	}
	for(i=n-1;i>=1;i--)
	{
		if(a[i]<=a[i+1])
			incStart[i]=1+incStart[i+1];
		else
			incStart[i]=1;
	}
	while(m--)
	{
		cin>>l>>r;
		if(incStart[l]+decEnd[r]>r-l+1)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}