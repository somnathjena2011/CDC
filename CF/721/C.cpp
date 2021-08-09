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
ll cnt[100005];
ll ending[100005];
int main()
{
	ll t,n,i,j,ans,p,c,e,res;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop1(i,n)
		cin>>a[i];
		map<ll,ll> prevInd;
		map<ll,ll> prevAdd;
		map<ll,ll> total;
		set<ll> st;
		loop1(i,n)
		{
			p=prevAdd[a[i]];
			j=prevInd[a[i]];
			c=total[a[i]];
			cnt[i]=p+1;
			prevAdd[a[i]]=p+1;
			prevInd[a[i]]=i;
			total[a[i]]+=((i-j-1)*p+cnt[i]);
			ending[i]=total[a[i]];
			st.insert(a[i]);
		}
		for(auto el:st)
		{
			p=prevAdd[el];
			j=prevInd[el];
			total[el]+=((n-j)*p);
		}
		ans=0;res=0;
		// for(auto el:st)
		// {
		// 	cout<<el<<'\n';
		// 	cout<<total[el]<<'\n';
		// }
		for(i=n-1;i>0;i--)
		{
			res=res+((total[a[i]]-ending[i])-((n-i)*cnt[i]));
			ans=ans+res;
		}
		cout<<ans<<'\n';
	}
	return 0;
}