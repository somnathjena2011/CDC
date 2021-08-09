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
	int t,n,m,i,j,k,l,o,c;
	cin>>t;string s;
	int a[1005];
	while(t--)
	{
		cin>>n>>m;
		cin>>s;
		loop0(i,n)
		a[i]=1000000009;
		for(i=0;i<n;i++)
		{
			if(s[i]=='1')
				a[i]=0;
			else
			{
				j=i;
				while(j<n&&s[j]=='0')
					j++;
				j--;
				if(i==0&&j==n-1)
					break;
				if(i==0)
				{
					l=1;
					for(k=j;k>=0;k--)
					{
						a[k]=l;l++;
					}
				}
				else if(j==n-1)
				{
					l=1;
					for(k=i;k<n;k++)
					{
						a[k]=l;l++;
					}
				}
				else if(i!=j)
				{
					l=(j-i)+1;
					o=l/2;c=1;
					for(k=1;k<=o;k++)
					{
						a[i+k-1]=c;
						++c;
					}
					c=1;
					for(k=1;k<=o;k++)
					{
						a[j-k+1]=c;
						c++;
					}
				}
				i=j;
			}
		}
		string ans="";
		for(i=0;i<n;i++)
		{
			if(a[i]<=m)
				ans.pb('1');
			else
				ans.pb('0');
		}
		cout<<ans<<'\n';
	}
	return 0;
}