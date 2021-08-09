#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,d,p;
	cin>>n;
	set<int,greater<int>> slots;
	vector<vector<int>> jobs(n,vector<int>(3,0));
	for(i=0;i<n;i++)
	{
		slots.insert(i);
		cin>>p>>d;
		jobs[i][0]=p;jobs[i][1]=d;jobs[i][2]=i;
	}
	sort(jobs.begin(),jobs.end(),[](vector<int>& a,vector<int>& b){
		return a[0]>b[0];
	});
	vector<int> done(n,-1);
	int prof=0;
	for(i=0;i<n;i++)
	{
		d=min(n,jobs[i][1])-1;
		auto it=slots.lower_bound(d);
		if(it!=slots.end())
		{
			prof+=jobs[i][0];
			done[*it]=jobs[i][2];
			slots.erase(it);
		}
	}
	cout<<prof<<'\n';
	for(i=0;i<n;i++)
	{
		if(done[i]>=0)
			cout<<done[i]<<' ';
	}
	cout<<'\n';
	return 0;
}