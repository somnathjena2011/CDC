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
	int t,s1,s2,s3,s4;
	cin>>t;
	while(t--)
	{
		cin>>s1>>s2>>s3>>s4;
		if(s3>s1&&s3>s2&&s4>s1&&s4>s2)
			cout<<"NO\n";
		else if(s1>s3&&s1>s4&&s2>s3&&s2>s4)
			cout<<"NO\n";
		else
			cout<<"YES\n";
	}
	return 0;
}