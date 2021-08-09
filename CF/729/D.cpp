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
	ll n;
	cin>>n;
	vector<pair<char,ll>> seq;
	ll i,j,x,y;char c;
	for(i=0;i<n;i++)
	{
		cin>>c;
		if(c=='+')
			cin>>x;
		else
			x=0;
		seq.pb({c,x});
	}
}