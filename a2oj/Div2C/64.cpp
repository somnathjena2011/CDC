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
	int n,p,a,b,d;
	cin>>n>>p;
	int to[n+1]={0};
	int fr[n+1]={0};
	int tow[n+1]={0};
	int frw[n+1]={0};
	int i,j;
	loop0(i,p)
	{
		cin>>a>>b>>d;
		to[a]=b;
		tow[a]=d;
		fr[b]=a;
		frw[b]=d;
	}
	int f,t,mw;int sum=0;
	vector<vector<int>> ans;
	loop1(i,n)
	{
		if(to[i]&&!fr[i])
		{
			f=i;
			t=i;
			mw=INT_MAX;
			while(to[t]!=0)
			{
				if(tow[t]<mw)
					mw=tow[t];
				t=to[t];
			}
			vector<int> curr={f,t,mw};
			++sum;
			ans.pb(curr);
		}
	}
	cout<<sum<<'\n';
	for(auto v:ans)
	{
		for(auto el:v)
			cout<<el<<' ';
		cout<<'\n';
	}
	return 0;
}