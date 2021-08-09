#include<bits/stdc++.h>
using namespace std;
void sort(vector<pair<int,int>>& a,vector<int>& count,int s,int e)
{
	if(s>=e)
		return;
	int m=s+(e-s)/2;
	sort(a,count,s,m);
	sort(a,count,m+1,e);
	vector<pair<int,int>> l,r;
	int i,j,k;
	for(i=s;i<=m;i++)
		l.push_back(a[i]);
	for(i=m+1;i<=e;i++)
		r.push_back(a[i]);
	i=0;j=0;k=s;
	while(i<l.size()&&j<r.size())
	{
		if(r[j].first<=l[i].first)
		{
			count[r[j].second]+=i;
			a[k]=r[j];
			j++;
		}
		else
		{
			a[k]=l[i];
			i++;
		}
		k++;
	}
	while(i<l.size())
	{
		a[k]=l[i];
		k++;i++;
	}
	while(j<r.size())
	{
		count[r[j].second]+=i;
		a[k]=r[j];
		k++;j++;
	}
}
int main()
{
	int n,i;
	cin>>n;
	vector<int> a(n);
	for(i=0;i<n;i++)
		cin>>a[i];
	vector<pair<int,int>> p(n);
	vector<int> count(n,0);
	for(i=0;i<n;i++)
		p[i]={a[i],i};
	sort(p,count,0,n-1);
	for(i=0;i<n;i++)
		cout<<count[i]<<' ';
	cout<<'\n';
	return 0;
}