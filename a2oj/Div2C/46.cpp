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
	int n,i;
	cin>>n;
	loop0(i,n)
	cin>>a[i];
	sort(a,a+n);
	int x,j,co,prev;
	if(a[0]==a[n-1]&&a[0]==1)
	{
		for(i=0;i<n-1;i++)
			cout<<1<<' ';
		cout<<2<<'\n';
	}
	else
	{
		i=0;prev=1;
		while(i<n)
		{
			for(j=i;j<n;j++)
			{
				if(a[j]!=a[i])
					break;
			}
			co=j-i;
			if(a[i]==1)
			{
				for(x=1;x<=co;x++)
					cout<<1<<' ';
				prev=1;
			}
			else
			{
				cout<<prev<<' ';
				for(x=1;x<co;x++)
					cout<<a[i]<<' ';
				prev=a[i];
			}
			i=j;
		}
		cout<<'\n';
	}
	return 0;
}