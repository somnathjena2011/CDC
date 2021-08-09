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
ll a[200005];
int main()
{
	ll t,n,i,j,x,y,ans,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop0(i,n)
		cin>>a[i];
		sum=0;
		if(n==1)
		{
			cout<<0<<'\n';
			continue;
		}
		sort(a,a+n);
		x=1;
		for(i=1;i<n;i++)
		{
			if(a[i]!=a[i-1])
			{
				x=0;
				break;
			}
		}
		if(x)
		{
			cout<<0<<'\n';
			continue;
		}
		sum=0;
		loop0(i,n)
		sum+=a[i];
		if(sum%n!=0)
		{
			cout<<-1<<'\n';
		}
		else
		{
			ans=0;x=0;
			for(i=n-1;i>0;i--)
			{
				x+=a[i];
				y=sum/n;
				if(a[i-1]>y)
					continue;
				else
				{
					ans=n-i;
					break;
				}
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}