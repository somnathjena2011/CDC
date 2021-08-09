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
	int t,i,j,n,l,m,li,mi,ans,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		loop0(i,n)
		cin>>a[i];
		if(n<=2)
		{
			cout<<n<<'\n';
			continue;
		}
		l=a[0];m=a[0];
		li=mi=0;
		for(i=1;i<n;i++)
		{
			if(a[i]>m)
			{
				m=a[i];
				mi=i;
			}
			if(a[i]<l)
			{
				l=a[i];
				li=i;
			}
		}
		x=min(li,mi);
		y=max(li,mi);
		ans=y+1;
		ans=min(ans,n-x);
		ans=min(ans,x+1+(n-y));
		cout<<ans<<'\n';
	}
	return 0;
}