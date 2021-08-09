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
	int n,i,j;
	cin>>n;
	pair<int,int> a[n+1];
	loop1(i,n)
	{
		cin>>j;
		a[i]={j,i};
	}
	sort(a+1,a+n+1);
	int maxi=a[n].ff;
	vector<pair<int,int>> x,y;
	int t=1;
	for(i=n;i>=1;i--)
	{
		if(t)
			x.pb(a[i]);
		else
			y.pb(a[i]);
		t=!t;
	}
	int xsum=0,ysum=0;
	for(auto p:x)
		xsum+=p.ff;
	for(auto p:y)
		ysum+=p.ff;
	while(abs(xsum-ysum)>maxi&&abs((int)(x.size()-y.size()))<=1)
	{
		j=x[0].ff;
		i=x[0].ss;
		x.erase(x.begin());
		xsum-=j;
		ysum+=j;
		y.pb({j,i});
	}
	cout<<x.size()<<'\n';
	for(auto p:x)
		cout<<p.ss<<' ';
	cout<<'\n';
	cout<<y.size()<<'\n';
	for(auto p:y)
		cout<<p.ss<<' ';
	cout<<'\n';
	return 0;
}