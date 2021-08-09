#include<bits/stdc++.h>
using namespace std;
class Set
{
public:
	int* sets;
	Set(int n)
	{
		sets=new int[n+1];
		for(int i=0;i<=n;i++)
			sets[i]=i;
	}
	int Find(int i)
	{
		if(i==sets[i])
			return i;
		return sets[i]=Find(sets[i]);
	}
	void Union(int i,int j)
	{
		sets[j]=i;
	}
};
int main()
{
	int n,i,j,d,p;
	cin>>n;
	Set slots(n);
	vector<vector<int>> jobs(n,vector<int>(3,0));
	for(i=0;i<n;i++)
	{
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
		d=min(n,jobs[i][1]);
		j=slots.Find(d);
		if(j!=0)
		{
			done[j-1]=jobs[i][2];
			prof+=jobs[i][0];
			slots.Union(slots.Find(j-1),j);
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