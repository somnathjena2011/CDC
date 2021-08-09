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
	ll t,i,k,n,j;
	cin>>t;
	ll a[1005];
	while(t--)
	{
		cin>>n;
		loop0(i,n)
		cin>>a[i];
		cout<<3*n<<'\n';
		for(i=0;i<n;i+=2)
		{
			if(a[i]<a[i+1])
			{
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<2<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<2<<' '<<i+1<<' '<<i+2<<'\n';
			}
			else
			{
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<2<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<2<<' '<<i+1<<' '<<i+2<<'\n';
				cout<<1<<' '<<i+1<<' '<<i+2<<'\n';
			}
		}
	}
	return 0;
}