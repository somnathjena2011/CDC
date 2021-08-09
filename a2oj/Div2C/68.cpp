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
	ll k,b,n,t;
	cin>>k>>b>>n>>t;
	if(t==1)
		cout<<n<<'\n';
	else
	{
		ll m,i,j,sum,ans;
		sum=k+b;
		i=0;
		while(sum<=min(t,1000000ll))
		{
			sum=sum*k+b;
			i++;
		}
		m=max(n-i,0ll);
		cout<<m<<'\n';
	}
	return 0;
}