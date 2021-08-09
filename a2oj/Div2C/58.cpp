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
	int n,i,j,k,l,f;
	cin>>n;
	string a[n];
	loop0(i,n)
	cin>>a[i];
	int row[n];
	int col[n];
	loop0(i,n)
	row[i]=col[i]=-1;
	loop0(i,n)
	{
		loop0(j,n)
		{
			if(a[i][j]=='.')
			{
				row[i]=j;
				col[j]=i;
			}
		}
	}
	loop0(i,n)
	{
		loop0(j,n)
		{
			if(row[i]==-1&&col[j]==-1)
			{
				cout<<-1<<'\n';
				return 0;
			}
		}
	}
	int rsum=0,csum=0;
	loop0(i,n)
	{
		if(row[i]>=0)++rsum;
		if(col[i]>=0)++csum;
	}
	if(rsum==n)
	{
		loop0(i,n)
		cout<<i+1<<' '<<row[i]+1<<'\n';
	}
	else if(csum==n)
	{
		loop0(i,n)
		cout<<col[i]+1<<' '<<i+1<<'\n';
	}
	else
		cout<<-1<<'\n';
	return 0;
}