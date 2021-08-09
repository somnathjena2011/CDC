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
ll ev[100005],od[100005];
int main()
{
	ll t,n,i,j,e,o,ans;
	cin>>t;
	while(t--)
	{
		cin>>n;
		e=0;o=0;
		loop0(i,n)
		{
			cin>>j;
			if(j&1)
				od[o++]=j;
			else
				ev[e++]=j;
		}
		ans=(e*(2*o+e-1))/2;
		loop0(i,o)
		{
			for(j=i+1;j<o;j++)
			{
				if(__gcd(od[i],od[j])>1)
					++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}