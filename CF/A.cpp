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
	int t,n,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		loop0(i,n)
		cin>>a[i];
		j=1;
		loop0(i,n)
		{
			k=(int)(sqrt(a[i]));
			if(k*k!=a[i])
			{
				j=0;
				break;
			}
		}
		if(j)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}