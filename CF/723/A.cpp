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
int main()
{
	int t,n,i,j,d;
	ll x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		ll a[2*n];
		loop0(i,2*n)
		cin>>a[i];
		sort(a,a+2*n);
		ll b[2*n];
		i=0;
		for(j=0;j<2*n;j+=2)
		{
			b[j]=a[i];
			++i;
		}
		i=2*n-1; 
		for(j=1;j<2*n;j+=2)
		{
			b[j]=a[i];
			--i;
		}
		for(i=0;i<2*n;i++)
			cout<<b[i]<<' ';
		cout<<'\n';
	}
	return 0;
}