#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
ll l[100005];
ll r[100005];
int main()
{
	ll t,n,c,x,i,j,ans,p,y;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>n>>c;
		map<ll,ll> mp;
		for(i=0;i<n;i++)
		{
			cin>>l[i]>>r[i];
			for(j=l[i]+1;j<r[i];j++)
				++mp[j];
		}
		ans=n;
		priority_queue<pair<ll,ll>> pq;
		for(auto pr:mp)
		{
			//cout<<pr.first<<' '<<pr.second;
			pq.push({pr.second,pr.first});
		}
		while(c--&&!pq.empty())
		{
			p=pq.top().second;
			y=pq.top().first;
			pq.pop();
			ans+=y;
		}
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}