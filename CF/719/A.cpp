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
	int t,n,i,j;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>n;
		cin>>s;
		map<char,int> mp;
		mp[s[0]]=1;
		j=0;
		for(i=1;i<n;i++)
		{
			if(s[i]==s[i-1])
				continue;
			else
			{
				if(mp[s[i]])
				{
					j=1;
					break;
				}
				else
					mp[s[i]]=1;
			}
		}
		if(j)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}