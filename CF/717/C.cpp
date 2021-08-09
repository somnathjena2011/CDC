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
	int n,i,j,x;
	cin>>n;
	int a[n];nit b[n];int pre[n];
	int sum=0;
	loop0(i,n)
	{
		cin>>a[i];
		sum+=a[i];
	}
	if(sum%2==1)
		cout<<0<<'\n';
	else
	{
		if((sum/2)%2==1)
		{
			x=sum/2;
			loop0(i,n)
			b[i]=a[i];
			sort(b,b+n);
			pre[0]=b[0];
			for(i=1;i<n;i++)
				pre[i]=pre[i-1]+b[i];
			int exists=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<i;j++)
				{
					if(pre[i]-pre[j]==x)
					{
						exists=1;
						break;
					}
				}
				if(pre[i]==x)
				{
					exists=1;
					break;
				}
				if(exists)
					break;
			}
			if(!exists)
				cout<<0<<'\n';
			else
			{
				cout<<1<<'\n';
				loop0(i,n)
				{
					if(a[i]%2==1)
					{
						cout<<a[i]<<'\n';
						break;
					}
				}
			}
		}
		else
		{
			x=sum/2;
			loop0(i,n)
			b[i]=a[i];
			sort(b,b+n);
			pre[0]=b[0];
			for(i=1;i<n;i++)
				pre[i]=pre[i-1]+b[i];
			int exists=0;
			for(i=0;i<n;i++)
			{
				for(j=0;j<i;j++)
				{
					if(pre[i]-pre[j]==x)
					{
						exists=1;
						break;
					}
				}
				if(pre[i]==x)
				{
					exists=1;
					break;
				}
				if(exists)
					break;
			}
			if(!exists)
				cout<<0<<'\n';
			else
			{
				int odd=-1;
				loop0(i,n)
				{
					if(a[i]%2==1)
					{
						odd=i;
						break;
					}
				}
				if(odd>-1)
				{
					cout<<1<<'\n';
					cout<<odd<<'\n';
				}
				else
				{
					odd=-1;
					loop0(i,n)
					{
						if((a[i]/2)%2==1)
						{
							odd=i;
							break;
						}
					}
					if(odd>-1)
					{
						cout<<1<<'\n';
						cout<<odd<'\n';
					}
					else
					{
						
					}
				}
			}
		}
	}
}