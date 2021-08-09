#include<bits/stdc++.h>
using namespace std;
int search(vector<vector<int>>& jobs,int s,int e,int t)
{
	int m;
	int ans=-1;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(jobs[m][1]<=t)
		{
			ans=m;
			s=m+1;
		}
		else
			e=m-1;
	}
	return ans;
}
int main()
{
	int n,i,j,s,f,p;
	cin>>n;
	vector<vector<int>> jobs(n,vector<int>(4,0));
	for(i=0;i<n;i++)
	{
		cin>>s>>f>>p;
		jobs[i][0]=s;
		jobs[i][1]=f;
		jobs[i][2]=p;
		jobs[i][3]=i;
	}
	sort(jobs.begin(),jobs.end(),[](vector<int>& a,vector<int>& b){
		return a[1]<b[1] || (a[1]==b[1]&&a[0]<=b[0]);
	});
	vector<int> dp(n,0);
	vector<int> pre(n,-1);
	dp[0]=jobs[0][2];pre[0]=-1;
	for(i=1;i<n;i++)
	{
		j=search(jobs,0,i-1,jobs[i][0]);
		p=jobs[i][2];
		if(j>=0)
		{
			if(dp[j]+p>dp[i-1])
			{
				dp[i]=dp[j]+p;
				pre[i]=j;
			}
			else
			{
				dp[i]=dp[i-1];
				pre[i]=i-1;
			}
		}
		else
		{
			if(p>dp[i-1])
			{
				dp[i]=p;
				pre[i]=-1;
			}
			else
			{
				dp[i]=dp[i-1];
				pre[i]=i-1;
			}
		}
	}
	vector<int> ans;
	int last=n-1;
	int prof=0;
	while(last!=-1)
	{
		j=pre[last];
		if(j>=0&&dp[j]==dp[last])
			last=j;
		else
		{
			prof+=jobs[last][2];
			ans.push_back(jobs[last][3]);
			last=pre[last];
		}
	}
	reverse(ans.begin(),ans.end());
	cout<<prof<<'\n';
	for(int ids:ans)
		cout<<ids<<' ';
	cout<<'\n';
	return 0;
}