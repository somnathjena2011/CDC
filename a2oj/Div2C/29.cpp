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
ll a[100005];
int main()
{
	ll n,k;
	cin>>n>>k;
	ll m=n/2;
	if(k<m)
		cout<<-1<<'\n';
	else if(n==1&&k==0)
		cout<<1<<'\n';
	else if(n==1&&k>0)
		cout<<-1<<'\n';
	else
	{
		ll i,j;
		j=1;
		loop0(i,m-1)
		{
			a[2*i]=j;
			j++;
			a[2*i+1]=j;
			j++;
		}
		ll rem=k-m+1;
		ll sum=rem;
		while(sum<j)
			sum+=rem;
		a[2*m-2]=sum;
		a[2*m-1]=sum+rem;
		if(n%2==1)
			a[n-1]=a[n-2]+1;
		loop0(i,n)
		cout<<a[i]<<' ';
		cout<<'\n';
	}
	return 0;
}