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
// int a[200005];
// int dp[200005];
int gcd(int x,int y)
{
	ll a,c,b;
	if(y>x)
	{
		b=x;
		a=y;
	}
	else
	{
		a=x;
		b=y;
	}
	if(a%b==0)
		return b;
	while(b>0)
	{
		a=a%b;
		c=a;
		a=b;
		b=c;
	}
	return a;
}
int main()
{
	int n,i,j,k,l;
	cin>>n;
	set<int> coprime,self;
	coprime.insert(1);
	for(i=2;i<=n;i++)
	{
		if(gcd(i,n)==1)
		{
			if((i*i)%n!=1)
				coprime.insert(i);
			else
				self.insert(i);
		}
	}
	k=coprime.size();
	l=self.size();
	if(l>2)
	{
		vector<int> ans;
		for(auto el:coprime)
			ans.pb(el);
		for(auto el:self)
			ans.pb(el);
		sort(ans.begin(),ans.end());
		cout<<ans.size()<<'\n';
		for(auto el:ans)
			cout<<el<<' ';
		cout<<'\n';
	}
	else
	{
		cout<<coprime.size()<<'\n';
		for(auto el:coprime)
			cout<<el<<' ';
		cout<<'\n';
	}
	return 0;
}
