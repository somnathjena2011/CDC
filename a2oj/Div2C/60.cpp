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
	int n,k,i,s;
	cin>>n>>k;
	s=(n*(n-1))/2;
	if(k>=s)
		cout<<"no solution\n";
	else
	{
		int mult=n;
		int x=0,y=0;
		loop0(i,n)
		{
			cout<<x<<' '<<y<<'\n';
			x++;y+=n;
		}
	}
	return 0;
}