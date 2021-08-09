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
	ll t,i,j,n,f,c,x,g,y,z,ans,diff,d,h,pz,pn;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop0(i,n)
		cin>>a[i];
		//unordered_map<ll,ll> mp;
		if(n==1)
		{
			cout<<1<<'\n';
			continue;
		}
		sort(a,a+n);
		g=0;c=0;z=0;pz=0;pn=0;
		loop0(i,n)
		{
			if(a[i]<0)
			{
				pn=1;
				++c;
			}
			else if(a[i]==0)
			{
				++z;pz=1;
			}
			else
				g=1;
		}
		if(a[0]<0&&a[1]<=0)
			diff=abs(a[0]-a[1]);
		else
			diff=0;
		for(i=1;i<n-1;i++)
		{
			if(a[i]<0&&a[i+1]<=0)
			{
				d=abs(a[i]-a[i+1]);
				if(d<diff)
					diff=d;
			}
			else
				break;
		}
		h=0;
		for(i=0;i<n;i++)
		{
			if(a[i]<=0)
				continue;
			else if(a[i]<=diff)
			{
				h=1;
				break;
			}
			else
				break;
		}
		if(!h)
		{
			ans=c+z;
			if(pz+g>ans)
				ans=pz+g;
			if(pn+g>ans)
				ans=pn+g;
			cout<<ans<<'\n';
		}
		else
		{
			ans=c+z;
			if(c+pz+g>ans)
				ans=c+pz+g;
			cout<<ans<<'\n';
		}
	}
	return 0;
}