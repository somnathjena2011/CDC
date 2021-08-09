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
	int t,n,i,j,g,x,y;
	string s;
	int d,k;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		vector<int> ans(n);
		map<pair<int,int>,int> mp;
		d=0;k=0;
		if(s[0]=='D')
		{
			++d;
			ans[0]=1;
			mp[{1,0}]=0;
		}
		else
		{
			++k;
			ans[0]=1;
			mp[{0,1}]=0;
		}
		for(i=1;i<n;i++)
		{
			if(s[i]=='D')
				++d;
			else
				++k;
			if(k==0)
			{
				mp[{d,0}]=i;
				ans[i]=ans[mp[{d-1,0}]]+1;
			}
			else
			{
				g=__gcd(d,k);
				x=d/g;
				y=k/g;
				if(mp.find({x,y})!=mp.end())
				{
					ans[i]=ans[mp[{x,y}]]+1;
					mp[{x,y}]=i;
				}
				else
				{
					ans[i]=1;
					mp[{x,y}]=i;
				}
			}
		}
		for(i=0;i<n;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}