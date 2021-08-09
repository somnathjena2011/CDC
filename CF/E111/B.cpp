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
	ll t,a,b,n,i,j,k,l,m,z,o,ans;char c;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		string s;
		cin>>s;
		ans=0;
		i=0;z=0;o=0;
		while(i<n)
		{
			c=s[i];
			j=i;
			while(j<n&&s[j]==c)
				j++;
			if(c=='1')
				++o;
			else
				++z;
			l=j-i;
			ans+=(a*l+b*l);
			i=j;
		}
		if(b>=0)
			cout<<(a+b)*n<<'\n';
		else
			cout<<a*n+(min(z,o)+1)*b<<'\n';
	}
	return 0;
}