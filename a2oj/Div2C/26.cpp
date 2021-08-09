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
int prime[10000001];
int cnt[10000001];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    mem(prime,0,10000001*sizeof(int));
    mem(cnt,0,10000001*sizeof(int));
	int n,m,i,j,l,k,r;
	for(i=2;i*i<=10000000;i++)
	{
		if(prime[i]==0)
		{
			for(j=i;j<=10000000;j+=i)
				prime[j]=i;
		}
	}
	for(i=2;i<=10000000;i++)
	{
		if(prime[i]==0)
			prime[i]=i;
	}
	cin>>n;
	while(n--)
	{
		cin>>i;
		int prev=0;
		while(i>1)
		{
			if(prime[i]!=prev)
			{
				prev=prime[i];
				++cnt[prime[i]];
			}
			i/=prime[i];
		}
	}
	loop1(i,10000000)
	cnt[i]=cnt[i-1]+cnt[i];
	cin>>m;
	while(m--)
	{
		cin>>l>>r;
		if(r>10000000)
			r=10000000;
		if(l>9999999)
			l=10000000;
		cout<<cnt[r]-cnt[l-1]<<'\n';
	}
	return 0;
}