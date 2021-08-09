#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp1[51][51][26],dp2[51][51][26];
int main()
{
	ll t,l,i,j,k,x,c,m,f,ans;
	string a,b;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>l;
		cin>>a;
		cin>>b;
		for(i=0;i<l;i++)
			for(j=0;j<l;j++)
				for(k=0;k<26;k++)
					dp1[i][j][k]=dp2[i][j][k]=0;
		for(i=0;i<l;i++)
			dp1[i][i][a[i]-'A']=1;
		for(m=1;m<l;m++)
		{
			for(i=0;i<l-m;i++)
			{
				j=i+m;
				for(k=0;k<26;k++)
					dp1[i][j][k]=dp1[i][j-1][k];
				++dp1[i][j][a[j]-'A'];
			}
		}
		for(i=0;i<l;i++)
			dp2[i][i][b[i]-'A']=1;
		for(m=1;m<l;m++)
		{
			for(i=0;i<l-m;i++)
			{
				j=i+m;
				for(k=0;k<26;k++)
					dp2[i][j][k]=dp2[i][j-1][k];
				++dp2[i][j][b[j]-'A'];
			}
		}
		ans=0;f=0;
		for(i=0;i<l;i++)
		{
			for(j=i;j<l;j++)
			{
				for(m=0;m<=l-(j-i+1);m++)
				{
					f=1;
					for(k=0;k<26;k++)
					{
						if(dp1[i][j][k]!=dp2[m][m+(j-i)][k])
						{
							f=0;
							break;
						}
					}
					if(f)
					{
						++ans;
						break;
					}
				}
			}
		}
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}