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
	int t,n,m,i,j;
	bool ro,re,bo,be;int o,e;char c;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		string grid[n];
		loop0(i,n)
		cin>>grid[i];
		ro=re=bo=be=0;
		e=0;
		loop0(i,n)
		{
			loop0(j,m)
			{
				if(grid[i][j]=='.')
					continue;
				else if(grid[i][j]=='R')
				{
					o=i+j;
					if(o&1)
						ro=1;
					else
						re=1;
				}
				else
				{
					o=i+j;
					if(o&1)
						bo=1;
					else
						be=1;
				}
				if((ro&&bo)||(re&&be)||(ro&&re)||(bo&&be))
				{
					e=1;
					break;
				}
			}
			if(e)
				break;
		}
		if(e)
			cout<<"NO\n";
		else
		{
			if(!ro&&!re&&!bo&&!be)
			{
				ro=1;be=1;
			}
			else if(ro)
			{
				re=0;be=1;bo=0;
			}
			else if(re)
			{
				ro=0;bo=1;be=0;
			}
			else if(bo)
			{
				be=0;re=1;ro=0;
			}
			else
			{
				bo=0;ro=1;re=0;
			}
			cout<<"YES\n";
			for(i=0;i<n;i++)
			{
				for(j=0;j<m;j++)
				{
					o=i+j;
					if(o&1)
						c=ro?'R':'W';
					else
						c=re?'R':'W';
					cout<<c;
				}
				cout<<'\n';
			}
		}
	}
	return 0;
}