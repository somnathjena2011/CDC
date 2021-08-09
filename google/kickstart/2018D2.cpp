#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<ll,ll> ballo[100005];
pair<ll,ll> tower[100005];
bool isRel(ll a,ll b)
{
	if(tower[a].second<=tower[b].second-(abs(tower[b].first-tower[a].first)))
		return false;
	return true;
}
ll findLeft(vector<ll>& rel,ll bx)
{
	ll s=0;ll e=rel.size()-1; ll m;
	ll ans=-1;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(tower[rel[m]].first<=bx)
		{
			ans=rel[m];
			s=m+1;
		}
		else
			e=m-1;
	}
	return ans;
}
ll findRight(vector<ll>& rel,ll bx)
{
	ll s=0;ll e=rel.size()-1; ll m;
	ll ans=-1;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(tower[rel[m]].first>=bx)
		{
			ans=rel[m];
			e=m-1;
		}
		else
			s=m+1;
	}
	return ans;
}
ll checkLeft(vector<ll>& rel,ll b)
{
	ll bx=ballo[b].first;
	ll ti=findLeft(rel,bx);
	if(ti<0)
		return 0;
	if(tower[ti].second<ballo[b].second)
		return 0;
	if(ballo[b].second<=tower[ti].second-abs(tower[ti].first-ballo[b].first))
		return 1;
	return 0;
}
ll checkRight(vector<ll>& rel,ll b)
{
	ll bx=ballo[b].first;
	ll ti=findRight(rel,bx);
	if(ti<0)
		return 0;
	if(tower[ti].second<ballo[b].second)
		return 0;
	if(ballo[b].second<=tower[ti].second-abs(tower[ti].first-ballo[b].first))
		return 1;
	return 0;
}
int main()
{
	ll t,n,k,p1,p2,a1,b1,c1,m1,h1,h2,a2,b2,c2,m2;
	ll x1,x2,a3,b3,c3,m3,y1,y2,a4,b4,c4,m4;
	ll i,j,l,c;
	ll ans=0;ll sum=0;ll diff=0;
	cin>>t;
	for(c=1;c<=t;c++)
	{
		cin>>n>>k;
		cin>>p1>>p2>>a1>>b1>>c1>>m1;
		cin>>h1>>h2>>a2>>b2>>c2>>m2;
		cin>>x1>>x2>>a3>>b3>>c3>>m3;
		cin>>y1>>y2>>a4>>b4>>c4>>m4;
		tower[0]={p1,h1};tower[1]={p2,h2};
		ballo[0]={x1,y1};ballo[1]={x2,y2};
		for(i=2;i<n;i++)
		{
			j=(a1*tower[i-1].first+b1*tower[i-2].first+c1)%m1+1;
			l=(a2*tower[i-1].second+b2*tower[i-2].second+c2)%m2+1;
			tower[i]={j,l};
		}
		for(i=2;i<k;i++)
		{
			j=(a3*ballo[i-1].first+b3*ballo[i-2].first+c3)%m3+1;
			l=(a4*ballo[i-1].second+b4*ballo[i-2].second+c4)%m4+1;
			ballo[i]={j,l};
		}
		sort(tower,tower+n);
		sort(ballo,ballo+k);
		vector<ll> rel;
		rel.push_back(0);
		for(i=1;i<n;i++)
		{
			if(rel.empty())
				rel.push_back(i);
			else
			{
				if(!isRel(i,rel.back()))
					continue;
				else
				{
					while(!rel.empty()&&!(isRel(i,rel.back())&&isRel(rel.back(),i)))
						rel.pop_back();
					rel.push_back(i);
				}
			}
		}
		ans=0;
		for(i=0;i<k;i++)
		{
			if(checkLeft(rel,i)||checkRight(rel,i))
				++ans;
		}
		cout<<"Case #"<<c<<": "<<ans<<'\n';
	}
	return 0;
}