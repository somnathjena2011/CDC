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
	int t,n,i,j,sum;
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum=0;
		loop0(i,n)
		{
			cin>>j;
			sum+=j;
		}
		if(sum==n)
			cout<<0<<'\n';
		else if(sum<n)
			cout<<1<<'\n';
		else
			cout<<sum-n<<'\n';
	}
	return 0;
}