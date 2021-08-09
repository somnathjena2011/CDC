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
ll w[100005];
ll pre[100005];
ll post[100005];
int main()
{
	ll n,l,r,i,j,ql,qr,last,sum;
	cin>>n>>l>>r>>ql>>qr;
	loop1(i,n)
	cin>>w[i];
	pre[0]=0;
	post[n+1]=0;
	for(i=1;i<=n;i++)
		pre[i]=pre[i-1]+w[i];
	for(i=n;i>0;i--)
		post[i]=post[i+1]+w[i];
	ll ans=LONG_MAX;
	ll d;
	for(i=0;i<=n;i++)
	{
		j=n-i;
		if(i==j)
		{
			if(pre[i]*l+post[n-j+1]*r<ans)
				ans=pre[i]*l+post[n-j+1]*r;
		}
		else if(i<j)
		{
			d=j-i;
			if(pre[i]*l+post[n-j+1]*r+(d-1)*qr<ans)
				ans=pre[i]*l+post[n-j+1]*r+(d-1)*qr;
		}
		else
		{
			d=i-j;
			if(pre[i]*l+post[n-j+1]*r+(d-1)*ql<ans)
				ans=pre[i]*l+post[n-j+1]*r+(d-1)*ql;
		}
	}
	cout<<ans<<'\n';
	return 0;
}