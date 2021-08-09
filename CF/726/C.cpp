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
ll h[200005];
int main()
{
	ll t,n,i,j,diff;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop0(i,n)
		cin>>h[i];
		sort(h,h+n);
		diff=h[1]-h[0];
		j=0;
		for(i=2;i<n;i++)
		{
			if(h[i]-h[i-1]<diff)
			{
				diff=h[i]-h[i-1];
				j=i-1;
			}
		}
		cout<<h[j]<<' ';
		for(i=j+2;i<n;i++)
			cout<<h[i]<<' ';
		for(i=0;i<j;i++)
			cout<<h[i]<<' ';
		cout<<h[j+1]<<'\n';
	}
	return 0;
}