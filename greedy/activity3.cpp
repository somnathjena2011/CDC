/*
Given n jobs with their deadlines and profits
Each job takes 1 unit of time
Schedule the jobs such that profit is maximized
SOLUTION:
GREEDY
->Sort jobs in decreasing order of profits
->Pick the next job i
->Find the next empty slot in range min(n,deadline[i])-1 to 0
i.e. first maximum possible empty slot
->If slot avilable schedule it else this can't be scheduled
PROOF:
SEE COPY
TIME:
O(n2) [can be improved using disjoint set]
*/
#include<bits/stdc++.h>
using namespace std;
struct Job{
	int id;
	int profit;
	int deadline;
	Job(int i,int p,int d):id(i),profit(p),deadline(d){}
	Job(){}
};
bool compare(Job& j1,Job& j2)
{
	return (j1.profit>j2.profit)
	||(j1.profit==j2.profit&&j1.deadline>=j2.deadline);
}
int main()
{
	int n,i,j,p,d;
	cin>>n;
	Job jobs[n];
	int slots[n+1];
	for(i=0;i<n;i++)
	{
		cin>>p>>d;
		Job* job=new Job(i,p,d);
		jobs[i]=*job;
		slots[i]=-1;
	}
	slots[n]=-1;
	sort(jobs,jobs+n,compare);
	int prof=0;int x;
	for(i=0;i<n;i++)
	{
		x=min(jobs[i].deadline,n)-1;
		for(j=x;j>=0;j--)
		{
			if(slots[j]<0)
			{
				slots[j]=jobs[i].id;
				prof+=jobs[i].profit;
				break;
			}
		}
	}
	cout<<prof<<'\n';
	for(i=0;i<=n;i++)
	{
		if(slots[i]>=0)
			cout<<slots[i]<<' ';
	}
	cout<<'\n';
	return 0;
}