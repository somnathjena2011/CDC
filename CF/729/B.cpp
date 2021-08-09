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
bool check(ll n,ll a,ll b)
{
	if(n==1)
		return 1;
	if(a==b)
		return n%a==0||n%a==1;
	if(b==1)
		return 1;
	if(a==1)
		return n%b==1;
	if(n%b==1)
		return 1;
	ll p=a;
	while(p<=n)
	{
		if((n-p)%b==0)
			return 1;
		if(p*a<0)
			break;
		p*=a;
	}
	return 0;
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t,n,a,b,r,x,y;
	cin>>t;
	while(t--)
	{
		cin>>n>>a>>b;
		if(check(n,a,b))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}