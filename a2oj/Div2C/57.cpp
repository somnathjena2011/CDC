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
int prime[100005],a[100005];
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n,i,j,k,l,f;
	cin>>n;
	loop1(i,n)
	{
		cin>>a[i];
		prime[i]=1;
	}
	prime[0]=prime[1]=prime[2]=prime[6]=prime[8]=0;
	for(i=3;i*i<=n;i++)
	{
		if(prime[i])
		{
			for(j=i*i;j<=n;j+=i)
				prime[j]=0;
		}
	}
	f=0;
	for(i=3;i<=n;i++)
	{
		if(prime[i]&&n%i==0)
		{
			f=0;
			for(j=1;j<=n/i;j++)
			{
				f=1;
				for(k=j;k<=n;k+=(n/i))
				{
					if(!a[k])
					{
						f=0;
						break;
					}
				}
				if(f)
				{
					cout<<"YES\n";
					return 0;
				}
			}
		}
	}
	cout<<"NO\n";
	return 0;
}