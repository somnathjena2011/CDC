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
	int t,n,i,j,o,e;
	cin>>t;
	while(t--)
	{
		cin>>n;
		o=e=0;
		for(i=0;i<2*n;i++)
		{
			cin>>j;
			if(j&1)
				++o;
			else
				++e;
		}
		if(e==o)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}