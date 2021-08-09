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
int p[1000006];
int x[1000006];
int main()
{
	int n;
	cin>>n;
	int i,j,k;
	int ans=0;
	x[0]=0;
	loop1(i,n)
	{
		cin>>p[i];
		ans=ans^p[i];
		x[i]=x[i-1]^i;
	}
	for(i=2;i<=n;i++)
	{
		j=n/i;
		if(j%2==1)
			ans=ans^x[i-1];
		j=n%i;
		ans=ans^x[j];
	}
	cout<<ans<<'\n';
	return 0;
}