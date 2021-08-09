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
	ull t,n,i,j,d,c,ans;
	cin>>t;
	loop0(c,t)
	{
		cin>>n;
		if(n%2050!=0)
			cout<<-1<<'\n';
		else
		{
			i=n/2050;
			j=i;
			ans=0;
			while(j>0)
			{
				d=j%10;
				j/=10;
				ans+=d;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}