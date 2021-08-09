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
	ll t;
	ull n,i,j,s,ave,rem;
	cin>>t;
	while(t--)
	{
		cin>>n;s=0;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
			s+=a[i];
		}
		ave=s/n;
		rem=s-ave*n;
		cout<<rem*(n-rem)<<'\n';
	}
	return 0;
}