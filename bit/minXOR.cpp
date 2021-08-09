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
	int n,i,x=INT_MAX;
	cin>>n;
	int a[n];
	loop0(i,n)
	cin>>a[i];
	sort(a,a+n);
	loop0(i,n-1)
	x=min(x,a[i]^a[i+1]);
	cout<<x<<'\n';
	return 0;
}