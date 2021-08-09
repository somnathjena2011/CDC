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
ll max(ll a,ll b)
{
	return a>=b?a:b;
}
ll solve(string& s)
{
	ll d=s.size();
	ll ans=0;
	if(d==2)
		ans+=9;
	else if(d==3)
		ans+=18;
	else if(d>3)
	{
		ans=18;
		for(ll i=3;i<=d-1;i++)
			ans+=(9*(ll)pow(10,i-2));
	}
	ll i;ll j=0;
	j=(s[0]-'0')-1;
	ans+=(j*(ll)pow(10,max(0,d-2)));
	for(i=1;i<d-1;i++)
	{
		j=(s[i]-'0');
		if(j>0)
			ans+=(j*(ll)(pow(10,max(0,d-i-2))));
	}
	string s2=s.substr(0,d-1);
	s2.pb(s[0]);
	if(s2<=s)
		++ans;
	return ans;
}
int main()
{
	string l,r;
	cin>>l>>r;
	ll ans=0;
	ll ans1=solve(l);
	ll ans2=solve(r);
	//cout<<ans1<<' '<<ans2<<'\n';
	ans=ans2-ans1;
	if(l[0]==l[l.size()-1])
		++ans;
	cout<<ans<<'\n';
	return 0;
}