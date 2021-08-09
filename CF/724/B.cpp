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
	int t,n,i,j,f;
	cin>>t;
	string s;
	while(t--)
	{
		cin>>n;
		cin>>s;
		queue<string> q;
		q.push("");
		while(!q.empty())
		{
			string c=q.front();
			q.pop();
			if(s.find(c)==string::npos)
			{
				cout<<c<<'\n';
				break;
			}
			for(j=0;j<26;j++)
				q.push(c+(char)(j+'a'));
		}
	}
	return 0;
}