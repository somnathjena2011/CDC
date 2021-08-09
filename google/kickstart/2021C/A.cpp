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
ll power(ll x,ll y)
{
	if(y==0)
		return 1;
	if(y==1)
		return x%mod;
	if(x<=1)
		return x;
	ll xx=power(x,y/2);
	if(y%2==0)
		return (xx*xx)%mod;
	else
		return (((x*xx)%mod)*xx)%mod;
}
ll solve(string& s,ll n,ll k)
{
	if(n==1)
		return (ll)(s[0]-'a');
	if(n==2)
	{
		ll i;
		ll count=0;
		for(i=0;i<k;i++)
		{
			string str;
			str.pb((char)(i+'a'));
			str.pb((char)(i+'a'));
			if(str<s)
				count=(count+1)%mod;
		}
		return count;
	}
	ll mid=(n+1)/2; 
	ll i,j;ll ch;ll ans=0;
	ll x,y,st,e;
	for(i=0;i<mid;i++)
	{
		ch=(ll)(s[i]-'a');
		st=i;
		e=n-i-1;
		x=e-st-1;
		//cout<<"st="<<st<<" e="<<e<<" x="<<x<<" ch="<<ch<<'\n';
		if(x<0)x=0;
		x=(x+1)/2;
		ans=(ans+(power(k,x)*ch)%mod)%mod;
	}
	vector<char> v(n);
	for(i=0;i<mid;i++)
		v[i]=v[n-i-1]=s[i];
	string sss;

	for(char c:v)
		sss.pb(c);
	if(sss<s)
		ans=(ans+1)%mod;
	return ans;
}
int main()
{
	ll t,n,k,i,j,x,ans,c;
	cin>>t;
	string s;
	for(c=1;c<=t;c++)
	{
		cin>>n>>k;
		cin>>s;
		ans=solve(s,n,k);
		cout<<"Case #"<<c<<": "<<ans<<'\n';
	}
	return 0;
}