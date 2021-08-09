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
	int t,i,x,n,zc,xc,f,p;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int a[n];
		int xr[n];
		loop0(i,n)
		cin>>a[i];
		x=0;
		loop0(i,n)
		{
			x=x^a[i];
			xr[i]=x;
		}
		if(x==0)
			cout<<"YES\n";
		else
		{
			zc=0;
			xc=1;
			f=1;
			p=1;
			for(i=n-2;i>=0;i--)
			{
				if(p)
				{
					if(xr[i]==0)
					{
						//cout<<"i="<<i<<'\n';
						++zc;
						p=0;
					}
				}
				else
				{
					if(xr[i]==x)
					{
						++xc;
						p=1;
					}
				}
			}
			//loop0(i,n)
			//cout<<xr[i]<<' ';
			//cout<<'\n';
			//cout<<"x="<<x<<" xc="<<xc<<" zc="<<zc<<'\n';
			if(xc>1&&zc==xc-1)
				cout<<"YES\n";
			else
				cout<<"NO\n";
		}
	}
	return 0;
}