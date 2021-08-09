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
int a[502][502];
int main()
{
	int n,i,j,c,k,x,y;
	cin>>n;
	int p[n+1];
	loop1(i,n)
	cin>>p[i];
	loop1(i,n)
	{
		loop1(j,n)
		a[i][j]=-1;
	}
	for(i=n;i>=1;i--)
	{
		x=y=i;
		a[i][i]=p[i];
		for(c=2;c<=p[i];c++)
		{
			if(x+1<=n&&a[x+1][y]==-1)
			{
				a[x+1][y]=p[i];
				x++;
			}
			else if(y-1>=1&&a[x][y-1]==-1)
			{
				a[x][y-1]=p[i];
				y--;
			}
			//else if(x-1)
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=i;j++)
			cout<<a[i][j]<<' ';
		cout<<'\n';
	}
	return 0;
}