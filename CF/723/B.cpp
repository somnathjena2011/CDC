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
ll no[4]={1111111,11111,111,11};
int main()
{
	ll t;
	ll i,j,k,l,a,b,n,x,f;
	cin>>t;
	map<pair<ll,ll>,ll> mp;
	while(t--)
	{
		cin>>x;
		f=0;
		for(i=0;i<=10;i++)
		{
			for(j=0;j<=10;j++)
			{
				for(k=0;k<=10;k++)
				{
					n=i*1111111+j*11111+k*111;
					if(n<=x)
					{
						n=x-n;
						if(n%11==0)
						{
							f=1;
							break;
						}
					}
				}
				if(f==1)
					break;
			}
			if(f==1)
				break;
		}
		if(f==1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	return 0;
}