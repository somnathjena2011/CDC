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
	int n,i,j;
	cin>>n;
	int a[n];
	loop0(i,n)
	cin>>a[i];
	int ans=0;
	int next=0;
	int mask=0;int curr;
	for(j=30;j>=0;j--)
	{
		mask|=(1<<j);
		next=ans|(1<<j);
		set<int> st;
		for(i=0;i<n;i++)
			st.insert(a[i]&mask);
		for(int pre:st)
		{
			if(st.find(pre^next)!=st.end())
			{
				ans=next;
				break;
			}
		}
	}
	// int mask=0;int nans=0;
	// for(i=30;i>=0;i--)
	// {
	// 	mask|=(1<<i);
	// 	set<int> st;
	// 	loop0(j,n)
	// 	st.insert(mask&a[j]);
	// 	nans=ans|(1<<i);
	// 	for(auto pre:st)
	// 	{
	// 		if(st.find(pre^nans)!=st.end())
	// 		{
	// 			ans|=(1<<i);
	// 			break;
	// 		}
	// 	}
	// }
	cout<<ans<<'\n';
	return 0;
}