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
	ll l,r;
	cin>>l>>r;
	vector<ll> lucky;
	ll s=0;
	queue<ll> q;
	q.push(s);
	ll n;
	ll co=0;
	ll a,b;
	while(co<2047&&!q.empty())
	{
		n=q.size();
		while(n--)
		{
			s=q.front();
			q.pop();
			a=s*10+4;
			b=s*10+7;
			co+=2;
			lucky.pb(a);
			lucky.pb(b);
			q.push(a);
			q.push(b);
		}
	}
	while(!q.empty())
		q.pop();
	ll ans=0;
	ll i=l;ll next;
	while(i<=r)
	{
		auto it=lower_bound(lucky.begin(),lucky.end(),i);
		next=*it;
		if(next<=r)
		{
			ans+=(next*(next-i+1));
			i=next+1;
		}
		else
		{
			ans+=(next*(r-i+1));
			i=next;
		}
	}
	cout<<ans<<'\n';
	return 0;
}