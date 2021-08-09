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
	int n,k,i,j,l;
	string s;
	cin>>s;
	cin>>k;
	string pairs[k];
	loop0(i,k)
	cin>>pairs[i];
	n=s.size();
	char x,y;int ans=0;int c1=0,c2=0;
	loop0(l,k)
	{
		x=pairs[l][0];y=pairs[l][1];
		loop0(i,n)
		{
			if(s[i]==x||s[i]==y)
			{
				j=i;c1=c2=0;
				while(j<n)
				{
					if(s[j]==x)
						++c1;
					else if(s[j]==y)
						++c2;
					else
						break;
					j++;
				}
				i=j;i--;
				ans+=min(c1,c2);
			}
		}
	}
	cout<<ans<<'\n';
	return 0;
	return 0;
}