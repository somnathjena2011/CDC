/*
Given n activitiies with their start times and finish time
You can perform max 1 job at a time
Find max no jobs that can be done
SOLUTION(GREEDY):
->Sort jobs in increasing order of finish times first
and then increasing order of start times
->Pick the next job if start time is greater than finish time
of previously selected job
PROOF:
->Say 1,2,3,......,n are the jobs in increasing order of finish times
->Say you selected kth job at a point and this is the first job where
a job x with greater finish time would have given optimal soln
->Case 1: 
If x has start time greater than kth finish time,
then select kth job and then xth job<- better soln
->Case 2:
If x has start time less than kth finish time, then select kth job
and no of jobs at worst case remain the same
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,s,f;
	cin>>n;
	vector<vector<int>> jobs(n,vector<int>(2,0));
	for(i=0;i<n;i++)
		cin>>jobs[i][0]>>jobs[i][1];
	sort(jobs.begin(),jobs.end(),[](vector<int>& a,vector<int>& b){
		return a[1]<b[1] || (a[1]==b[1]&&a[0]<=b[0]);
	});
	int c=1; 
	f=jobs[0][1];
	for(i=1;i<n;i++)
	{
		if(jobs[i][0]>f)
		{
			f=jobs[i][1];
			++c;
		}
	}
	cout<<c<<'\n';
	return 0;
}