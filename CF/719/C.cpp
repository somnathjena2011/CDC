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
int ans[102][102];
int main()
{
	int t,n,i,j,k,l,c;
	cin>>t;
	while(t--)
	{
		cin>>n;
		if(n==1)
			cout<<1<<'\n';
		else if(n==2)
			cout<<-1<<'\n';
		else
		{
			c=1;
			for(i=1;i<=n-1;i++)
			{
				for(j=1;j<=n-i+1;j++)
				{
					ans[j][j+i-1]=c;
					c++;
				}
			}
			ans[1][n]=n*n-1;
			for(i=2;i<=n-1;i++)
			{
				for(j=i;j<=n;j++)
				{
					ans[j][j-i+1]=c;
					c++;
				}
			}
			ans[n][1]=n*n;
			for(i=1;i<=n;i++)
			{
				for(j=1;j<=n;j++)
					cout<<ans[i][j]<<' ';
				cout<<'\n';
			}
		}
	}
	return 0;
}