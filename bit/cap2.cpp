#include<bits/stdc++.h>
using namespace std;
int main()
{
	int persons;
	int caps;
	cin>>persons>>caps;
	vector<set<int>> collections(persons);
	int i,j,k;
	for(i=0;i<persons;i++)
	{
		cin>>j;
		while(j--)
		{
			cin>>k;
			collections[i].insert(k);
		}
	}
	vector<vector<int>> dp(caps+1,vector<int>(1<<persons,-1));
	auto f=[&](auto& self,int cap,int mask)->int {
		if(cap>caps)
			return mask==0?1:0;
		if(dp[cap][mask]!=-1)
			return dp[cap][mask];
		int ans=0;
		for(int person=0;person<persons;person++)
		{
			if((mask&(1<<person))&&
				collections[person].find(cap)!=collections[person].end())
				ans+=self(self,cap+1,mask^(1<<person));
		}
		ans+=self(self,cap+1,mask);
		dp[cap][mask]=ans;
		return dp[cap][mask];
	};
	int res=f(f,1,(1<<persons)-1);
	cout<<res<<'\n';
}