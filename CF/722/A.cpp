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
	int t,n,i,j,x;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		loop0(i,n)
		cin>>a[i];
		sort(a,a+n);
		j=1;
		for(i=1;i<n;i++)
		{
			if(a[i]==a[i-1])
				++j;
			else
				break;
		}
		cout<<n-j<<'\n';
	}
	return 0;
}