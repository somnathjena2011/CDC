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
int a[100005];
int main()
{
	int t,n,i,j,k,x,y,mini,f,c,l,len,diff,m,m2,co;
	cin>>t;
	while(t--)
	{
		cin>>n;
		loop1(i,n)
		cin>>a[i];
		c=0;
		vector<vector<int>> ans;
		for(i=1;i<n;i++)
		{
			// cout<<"i="<<i<<'\n';
			// for(j=1;j<=n;j++)
			// 	cout<<a[j]<<' ';
			// cout<<'\n';
			if(a[i]<=a[i+1])
			{
				if(a[i+1]!=a[i]+1)
				{
					ans.pb({i,i+1,a[i],a[i]+1});
					++c;
					a[i+1]=a[i]+1;
				}
			}
			else 
			{
				if(i==1)
				{
					if(a[i]!=a[i+1]+1)
					{
						ans.pb({i,i+1,a[i+1]+1,a[i+1]});
						++c;
						a[i]=a[i+1]+1;
					}
				}
				else
				{
					x=a[i+1]+1;
					while(!(__gcd(a[i-1],x)==1&&__gcd(x,a[i+1])==1))
					{
						//cout<<"Hello\n";
						++x;
					}
					if(a[i]!=a[i+1]+1)
					{
						ans.pb({i,i+1,x,a[i+1]});
						++c;
						a[i]=x;
					}
				}
			}
		}
		cout<<c<<'\n';
		for(auto v:ans)
			cout<<v[0]<<' '<<v[1]<<' '<<v[2]<<' '<<v[3]<<'\n';
	}
	return 0;
}