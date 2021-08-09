#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[5005];
int main()
{
	ll t,n,k,i,j,x,c,ans,d;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
			cin>>a[i];
		sort(a,a+n);
		c=0;ans=0;
		d=1;
		for(i=0;i<n;)
		{
			if(c<k&&a[i]>=d)
			{
				++c;
				++ans;
				++i;
			}
			else if(c==k)
			{
				c=0;
				++d;
			}
			else if(c<k&&a[i]<d)
			{
				++i;
			}
		}
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}