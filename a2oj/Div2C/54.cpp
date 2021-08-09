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
	int a,b;
	cin>>a>>b;
	int i,j,k,l;
	int f,g;f=g=0;
	int x1,x2,y1,y2;
	int sqa=a*a;int sqb=b*b;
	for(i=1;i<a;i++)
	{
		j=sqa-i*i;
		k=(int)sqrt(j);
		if(k*k==j)
		{
			f=1;
			x1=i;y1=k;
			g=__gcd(x1,y1);
			x2=-(y1/g);y2=x1/g;
			if(b%(int)sqrt(x2*x2+y2*y2)==0)
			{
				l=(int)sqrt(x2*x2+y2*y2);
				y2=(b*y2)/l;
				x2=(b*x2)/l;
				if(y2!=y1)
				{
					cout<<"YES\n";
					cout<<0<<' '<<0<<'\n';
					cout<<x1<<' '<<y1<<'\n';
					cout<<x2<<' '<<y2<<'\n';
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
	return 0;
}