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
	int n;
	cin>>n;
	int diff=0;int dir=1;int next=(n+1)/2; 
	int i;
	loop1(i,n)
	{
		cout<<next<<' ';
		++diff;
		if(dir==1)
		{
			next=next+diff;
			dir=0; 
		}
		else
		{
			next=next-diff;
			dir=1;
		}
	}
	cout<<'\n';
	return 0;
}