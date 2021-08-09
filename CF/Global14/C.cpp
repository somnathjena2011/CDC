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
int a[100005];
int main()
{
	int t,m,n,x,i,j,k;
	cin>>t;
	while(t--)
	{
		cin>>n>>m>>x;
		set<pair<int,int>> s;
		loop1(i,m)
		s.insert(mp(0,i));
		cout<<"YES\n";
		loop0(i,n)
		{
			cin>>a[i];
			auto p=s.begin();
			cout<<p->ss<<' ';
			j=p->ff;k=p->ss;
			s.erase(p);
			s.insert(mp(j+a[i],k));
		}
		cout<<'\n';
	}
	return 0;
}