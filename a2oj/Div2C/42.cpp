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
int solve(string& s,int i,int n,char p,string& ans)
{
	ans=s.substr(0,i);
	int j;
	char c=s[i];
	char d;
	int fix=0;
	for(d=c+1;d<=p;d++)
	{
		if(i-1>=0&&s[i-1]==d)
			continue;
		if(i-2>=0&&s[i-2]==d)
			continue;
		fix=1;
		break;
	}
	if(!fix)
		return 0;
	ans.pb(d);
	for(j=i+1;j<n;j++)
	{
		fix=0;
		for(char ch='a';ch<=p;ch++)
		{
			if(j-1>=0&&ans[j-1]==ch)
				continue;
			if(j-2>=0&&ans[j-2]==ch)
				continue;
			ans.pb(ch);
			fix=1;
			break;
		}
		if(!fix)
			return 0;
	}
	return 1;
}
int main()
{
	int n,p,i,j;
	cin>>n>>p;
	string s;
	cin>>s;
	string ans;
	for(i=n-1;i>=0;i--)
	{
		if(solve(s,i,n,(char)(p-1+'a'),ans))
		{
			//cout<<"i="<<i<<'\n';
			cout<<ans<<'\n';
			return 0;
		}
	}
	cout<<"NO\n";
	return 0;
}