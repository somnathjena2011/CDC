/*
Given n jobs, their start time, end time and profits
Can perform at max 1 job at a time
Max profit that can be obtained?
SOLUTION:
GREEDY FAILS:
->If we sort in increasing order of finish times
and choose job one by one->FAILS
e.g. S E P (Start end proft)
     1 3 1
     2 5 5
If we choose job one(as it has lesser finish time), 
we can't do 2nd job with higher profit
->If we choose in decreasing order of profits->FAILS
e.g. S E  P
     1 10 10
     1 2  5
     3 4  5
     4 6  5
If we choose job one(as it has highest profit).
we can't do other 3 jobs whose sum has higher proft
SOLUTION: DP
->Sort in increasing order of finish times
->For ith job dp[i]=maximum profit obtain by considering jobs
upto ith job(after sorting)
->dp[i]=max(dp[i-1]{Do not do this job},
			dp[j]+profit[i]{Where j is the latest job with finish time
			               <=start time of this job})
TIME=O(n^2)
Can be improved to O(nlogn) if we do binary search for
latest finish time<=start time of a given job
*/
#include<bits/stdc++.h>
using namespace std;
struct Job{
	int id;
	int start;
	int end;
	int profit;
	Job(){}
	Job(int i,int s,int e,int p)
	{
		id=i;start=s;end=e;profit=p;
	}
};
bool compare(Job& j1,Job& j2)
{
	return (j1.end<j2.end)||(j1.end==j2.end&&j1.start<=j2.start);
}
int search(Job jobs[],int s,int e,int k)
{
	int m;int ans=-1;
	while(s<=e)
	{
		m=s+(e-s)/2;
		if(jobs[m].end==k)
			return m;
		else if(jobs[m].end<k)
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
	int n,i,s,e,p;
	cin>>n;
	Job jobs[n];
	for(i=0;i<n;i++)
	{
		cin>>s>>e>>p;
		Job* job=new Job(i,s,e,p);
		jobs[i]=*job;
	}
	sort(jobs,jobs+n,compare);
	int dp[n];
	dp[0]=jobs[0].profit;int m;
	for(i=1;i<n;i++)
	{
		m=search(jobs,0,i-1,jobs[i].start);
		if(m==-1)
			dp[i]=max(dp[i-1],jobs[i].profit);
		else
			dp[i]=max(dp[i-1],jobs[i].profit+dp[m]);
	}
	cout<<dp[n-1]<<'\n';
	return 0;
}