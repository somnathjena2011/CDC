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
	int t,n,m,i,j,d,ans;
	cin>>t;
	string no;
	while(t--)
	{
		cin>>n;
		j=n;
		no="";
		while(j>0)
		{
			d=j%10;
			no=to_string(d)+no;
			j/=10;
		}
		m=no.size();
		ans=9*(m-1);
		for(i=1;i<=9;i++)
		{
			d=0;
			for(j=1;j<=m;j++)
				d=d*10+i;
			if(d<=n)
				++ans;
			else
				break;
		}
		cout<<ans<<'\n';
	}
	return 0;
}