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
	int t,n,m,k,i,j;
	cin>>t;
	int s=0;
	while(t--)
	{
		cin>>n>>m>>k;
		s=m*n-1;
		if(s==k)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}