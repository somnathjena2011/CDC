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
	ll t,i,n,m,l,j;
	cin>>t;
	string s;ll ans;ll ans2;
	while(t--)
	{
		cin>>n;
		cin>>s;
		vector<ll> stars;
		for(i=0;i<n;i++)
		{
			if(s[i]=='*')
				stars.pb(i);
		}
		l=stars.size();
		m=ceil((float)l/2)-1;
		ans=0;
		for(i=0;i<l;i++)
		{
			ans+=(abs(stars[m]-stars[i])-abs(m-i));
		}
		
		if(l%2==0)
		{
			m=l/2;
			ans2=0;
			for(i=0;i<l;i++)
			{
				ans2+=(abs(stars[m]-stars[i])-abs(m-i));
			}
			ans=min(ans,ans2);
		}
		cout<<ans<<'\n';
	}
	return 0;
}

