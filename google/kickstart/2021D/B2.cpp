#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
ll l[100005];
ll r[100005];
int main()
{
	ll t,n,c,x,i,j,ans,p,y,mi,ma,sum;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>n>>c;
		map<ll,ll> mp;
		mi=LONG_MAX;ma=LONG_MIN;
		for(i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
			mi=min(mi,l[i]);
			ma=max(ma,r[i]);
		}
		c=min(c,ma-mi-1);
		vector<pair<ll,ll>> points;
		for(i=0;i<n;i++)
		{
			points.push_back({l[i]+1,1});
			points.push_back({r[i],-1});
		}
		sort(points.begin(),points.end());
		ans=n;
		sum=points[0].second;
		for(i=1;i<points.size();i++)
		{
			mp[sum]+=(points[i].first-points[i-1].first);
			sum+=points[i].second;
		}
		vector<pair<ll,ll>> counts;
		for(auto pr:mp)
			counts.push_back(pr);
		sort(counts.begin(),counts.end(),greater<pair<ll,ll>>());
		for(auto pr:counts)
		{
			if(c<=0)
				break;
			p=pr.first;
			y=pr.second;
			if(c>=y)
			{
				ans+=(p*y);
				c-=y;
			}
			else
			{
				ans+=(p*c);
				c-=c;
			}
		}
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}