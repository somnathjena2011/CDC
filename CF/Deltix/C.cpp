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
	int t,n,i,j;
	cin>>t;
	int a[1005];
	while(t--)
	{
		cin>>n;
		loop0(i,n)
			cin>>a[i];
		vector<int> ans;
		for(i=0;i<n;i++)
		{
			if(a[i]==1)
				ans.pb(1);
			else
			{
				while(ans.back()!=a[i]-1)ans.pop_back();
				++ans.back();
			}
			for(j=0;j<ans.size()-1;j++)
				cout<<ans[j]<<'.';
			cout<<ans.back()<<'\n';
		}
	}
	return 0;
}