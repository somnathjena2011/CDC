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
int w[105];
int main()
{
	int t,n,x,i,j,sum;
	cin>>t;
	while(t--)
	{
		cin>>n>>x;
		sum=0;
		loop0(i,n)
		{
			cin>>w[i];
			sum+=w[i];
		}
		if(x>sum)
		{
			cout<<"YES\n";
			loop0(i,n)
			cout<<w[i]<<' ';
			cout<<'\n';
		}
		else if(x==sum)
			cout<<"NO\n";
		else
		{
			sum=0;
			sort(w,w+n);
			loop0(i,n)
			{
				if(sum+w[i]==x)
				{
					j=w[i];
					w[i]=w[i+1];
					w[i+1]=j;
				}
				sum+=w[i];
			}
			cout<<"YES\n";
			loop0(i,n)
			cout<<w[i]<<' ';
			cout<<'\n';
		}
	}
	return 0;
}