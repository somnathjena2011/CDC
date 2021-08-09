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
	ll t,n,i,j,m,k,x,e,o,f,g;
	cin>>t;
	while(t--)
	{
		cin>>n;
		vector<ll> v;e=0;o=0;
		loop0(i,n)
		{
			cin>>j;
			if(j&1)
				++o;
			else
				++e;
			v.pb(j);
		}
		m=n;
		sort(v.begin(),v.end());
		if(v[0]<0)
			cout<<"NO\n";
		else
		{
			g=__gcd(v[0],v[1]);
			for(i=2;i<n;i++)
				g=__gcd(g,v[i]);
			m=v[n-1]/g;
			if(v[0]==0)
				++m;
			if(m<=300)
			{
				cout<<"YES\n";
				cout<<m<<'\n';
				if(v[0]==0)
				{
					cout<<0<<' ';
					--m;
				}
				j=1;
				while(m)
				{
					cout<<g*j<<' ';
					j++;
					m--;
				}
				cout<<'\n';
			}
			else
				cout<<"NO\n";
		}
	}
	return 0;
}