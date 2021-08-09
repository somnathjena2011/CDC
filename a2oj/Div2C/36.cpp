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
int arr[200005];
int additions[200005];
int main()
{
	int n=1;
	int m;
	int t,x,a,k;
	cin>>m;
	double sum=0;
	cout.precision(15);
	additions[1]=0;
	arr[1]=0;
	while(m--)
	{
		cin>>t;
		if(t==1)
		{
			cin>>a>>x;
			sum+=(a*x);
			additions[a]+=x;
		}
		else if(t==2)
		{
			cin>>k;
			n++;
			arr[n]=k;
			additions[n]=0;
			sum+=arr[n];
		}
		else if(t==3)
		{
			additions[n-1]+=additions[n];
			sum-=arr[n];
			sum-=additions[n];
			n--;
		}
		cout<<sum/n<<'\n';
	}
	return 0;
}