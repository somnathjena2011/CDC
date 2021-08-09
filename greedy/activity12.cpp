#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,s,f,i;
	cin>>n;
	vector<vector<int>> jobs(n,vector<int>(3,0));
	for(i=0;i<n;i++)
	{
		cin>>s>>f;
		jobs[i][0]=s;
		jobs[i][1]=f;
		jobs[i][2]=i;
	}
	sort(jobs.begin(),jobs.end(),[](vector<int>& a,vector<int>& b){
		return a[1]<b[1] || (a[1]==b[1]&&a[0]<=b[0]);
	});
	vector<int> ans;
	ans.push_back(jobs[0][2]);
	int last=jobs[0][1];
	for(i=1;i<n;i++)
	{
		if(jobs[i][0]>=last)
		{
			ans.push_back(jobs[i][2]);
			last=jobs[i][1];
		}
	}
	for(int id:ans)
		cout<<id<<' ';
	cout<<'\n';
	return 0;
}