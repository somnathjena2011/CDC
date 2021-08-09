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
	ll t,g,c,i,j,k,n,s,ans;
	cin>>t;
	for(c=1;c<=t;c++)
	{
		cin>>g;
		ans=0;
		j=2*g;
		for(i=0;i*i<=j;i++)
		{
			if(j%(i+1)!=0)
				continue;
			n=j/(i+1);
			k=(n-i)/2;
			if(k!=0&&(i+1)*(i+2*k)==j)
			{
				++ans;
			}
			if((i+1)*(i+2*k)>j)
				break;
		}
		cout<<"Case #"<<c<<": "<<ans<<'\n';
	}
	return 0;
}