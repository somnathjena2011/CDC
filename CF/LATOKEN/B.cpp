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
	ll t,n,i,j,k,h,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> a;
		a.pb(0);
		loop0(i,n)
		{
			cin>>j;
			a.pb(j);
		}
		a.pb(0);
		ans=0;
		loop0(i,n+1)
		ans+=abs(a[i]-a[i+1]);
		priority_queue<pair<int,int>> pq;
		for(i=1;i<=n;i++)
			pq.push({a[i],i});
		while(!pq.empty())
		{
			h=pq.top().first;
			j=pq.top().second;
			pq.pop();
			if(a[j-1]>=h||a[j+1]>=h)
				continue;
			else
			{
				k=a[j-1]>a[j+1]?j-1:j+1;
				ans-=(h-a[k]);
				a[j]=a[k];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}