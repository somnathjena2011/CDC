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
	int t,n,k,i,j;
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		int a[n];
		loop0(i,n)
		cin>>a[i];
		loop0(i,n-1)
		{
			j=a[i];
			j=min(j,k);
			a[i]-=j;
			a[n-1]+=j;
			k-=j;
			if(k==0)
				break;
		}
		loop0(i,n)
		cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}