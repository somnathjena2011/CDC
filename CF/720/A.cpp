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
	ll t,a,b,x,y,z,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		if(b==1)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			x=b*a;
			y=(b-1)*a;
			z=(2*b-1)*a;
			cout<<x<<' '<<y<<' '<<z<<'\n';
		}
	}
	return 0;
}