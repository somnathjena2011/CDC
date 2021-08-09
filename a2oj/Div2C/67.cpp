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
int a[100005];
int main()
{
	int n,i;
	cin>>n;
	loop0(i,n)
	cin>>a[i];
	set<int> ans;
	set<int> cur;
	cur.insert(a[0]);
	ans.insert(a[0]);
	loop1(i,n-1)
	{
		set<int> next;
		for(auto el:cur)
			next.insert(el|a[i]);
		next.insert(a[i]);
		cur=next;
		for(auto el:cur)
			ans.insert(el);
	}
	cout<<ans.size()<<'\n';
	return 0;
}