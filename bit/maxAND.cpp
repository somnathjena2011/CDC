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
	int n,i,j,c;
	cin>>n;
	int a[n];
	loop0(i,n)
	cin>>a[i];
	int ans=0;int mask;
	for(i=30;i>=0;i--)
	{
		mask=ans|(1<<i);
		c=0;
		for(j=0;j<n;j++)
		{
			if((mask&a[j])==mask)
				++c;
			if(c==2)
				break;
		}
		if(c==2)
			ans|=mask;
	}
	// for(i=30;i>=0;i--)
	// {
	// 	mask=ans|(1<<i);
	// 	c=0;
	// 	loop0(j,n)
	// 	{
	// 		if((mask&a[j])==mask)
	// 			++c;
	// 	}
	// 	if(c>=2)
	// 		ans=ans|mask;
	// }
	cout<<ans<<'\n';
	return 0;
}