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
	int n,t,l,k,r,ans,sum,zero,one;
	cin>>n>>t;
	cin>>k;
	int i=0;int temp;
	int maxi=n;
	int mini=n;
	l=1;r=(n+1)/2;
	while(i<20)
	{
		cout<<"? "<<l<<" "<<r<<'\n';
		cin>>one;
		zero=r-one;
		temp=r;
		if(zero>=k)
		{
			maxi=r;
			r=mini+(maxi-mini)/2;
			if(temp==r)
			{
				cout<<r<<'\n';
				break;
			}
		}
		else
		{
			mini=r;
			r=mini+(maxi-mini)/2;
			if(temp==r)
			{
				cout<<r<<'\n';
				break;
			}
		}
		i++;
	}
	cout.flush();
	return 0;
}