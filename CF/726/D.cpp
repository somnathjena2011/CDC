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
	ll t,n,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n;
		x=(ll)log2(n);
		y=(ll)pow(2,x);
		if(n==1)
			cout<<"Bob\n";
		else if(n==y)
		{
			if(x&1)
				cout<<"Bob\n";
			else
				cout<<"Alice\n";
		}
		else
		{
			if(n&1)
				cout<<"Bob\n";
			else
				cout<<"Alice\n";
		}
	}
	return 0;
}