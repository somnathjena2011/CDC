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
int dp0[1000000],dp1[1000000];
ll parent(ll x,ll n)
{
	ll i;
	ll sum=0;
	i=n;
	while(sum+i<x)
	{
		sum+=i;
		i/=2;
	}
	ll next=sum+i;
	ll diff=x-sum;
	ll off=(diff+1)/2;
	return next+off;
}
int main()
{
	ll k,q,p,i,j,t,pp,ans;char c;
	cin>>k;
	ll n=(1<<k)-1;
	string str;
	cin>>str;
	vector<char> s(str.size());
	for(i=0;i<str.size();i++)
		s[i]=str[i];
	//cout<<"n="<<n<<'\n';
	for(i=1;i<=(1<<(k-1));i++)
	{
		if(s[i-1]=='0')
		{
			dp0[i]=1;dp1[i]=0;
		}
		else if(s[i-1]=='1')
		{
			dp0[i]=0;dp1[i]=1;
		}
		else
			dp0[i]=dp1[i]=1;
	}
	ll x,y,l,r;
	for( ;i<=n;i++)
	{
		y=(n+1)/2;
		l=2*(i-y)-1;r=2*(i-y);
		//cout<<"i="<<i<<" l="<<l<<" r="<<r<<'\n';
		if(s[i-1]=='0')
		{
			dp1[i]=0;
			dp0[i]=dp0[l]+dp1[l];
		}
		else if(s[i-1]=='1')
		{
			dp0[i]=0;
			dp1[i]=dp0[r]+dp1[r];
		}
		else
		{
			dp0[i]=dp0[l]+dp1[l];
			dp1[i]=dp0[r]+dp1[r];
		}
	}
	// for(i=1;i<=n;i++)
	// 	cout<<dp0[i]<<' ';
	// cout<<'\n';
	// for(i=1;i<=n;i++)
	// 	cout<<dp1[i]<<' ';
	//cout<<'\n';
	cin>>q;
	while(q--)
	{
		cin>>p>>c;
		if(c==s[p-1])
			cout<<dp0[n]+dp1[n]<<'\n';
		else
		{
			pp=p;
			s[p-1]=c;
			if(p<=(n+1)/2)
			{
				if(c=='0')
				{
					dp0[p]=1;dp1[p]=0;
				}
				else if(c=='1')
				{
					dp0[p]=0;dp1[p]=1;
				}
				else
					dp0[p]=dp1[p]=1;
			}
			else
			{
				y=(n+1)/2;
				l=2*(p-y)-1;r=2*(p-y);
				if(c=='?')
				{
					dp0[p]=dp0[l]+dp1[l];
					dp1[p]=dp0[r]+dp1[r];
				}
				else if(c=='0')
				{
					dp0[p]=dp0[l]+dp1[l];
					dp1[p]=0;
				}
				else
				{
					dp1[p]=dp0[r]+dp1[r];
					dp0[p]=0;
				}
			}
			pp=parent(p,y);
			//cout<<"p="<<p<<" pp="<<pp<<'\n';
			while(pp<=n)
			{
				//cout<<"p="<<p<<" pp="<<pp<<'\n';
				l=2*(pp-y)-1;r=2*(pp-y);
				if(s[pp-1]=='?')
				{
					dp0[pp]=dp0[l]+dp1[l];
					dp1[pp]=dp0[r]+dp1[r];
				}
				else if(s[pp-1]=='1')
				{
					dp0[pp]=0;
					dp1[pp]=dp0[r]+dp1[r];
				}
				else
				{
					dp0[pp]=dp0[l]+dp1[l];
					dp1[pp]=0;
				}
				p=pp;
				if(pp==1)
					break;
				pp=parent(pp,y);
			}
			cout<<dp0[n]+dp1[n]<<'\n';
		}
	}
	return 0;
}