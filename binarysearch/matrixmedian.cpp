#include<bits/stdc++.h>
using namespace std;
int search(vector<int>& A,int x)
{
	int n=A.size();
	int s=0,e=n-1,m;
	int ans=-1;
	while(s<=e)
	{
		m=s+(s-e)/2;
		if(A[m]<=x)
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
	int n,m;//m*m is odd
	cin>>n>>m;
	int i,j;
	vector<vector<int>> A(n,vector<int>(m,0));
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>A[i][j];
	int med=1+(n*m)/2;
	int mini=INT_MAX,maxi=INT_MIN,mid;
	for(i=0;i<n;i++)
	{
		mini=min(mini,A[i][0]);
		maxi=max(maxi,A[i][m-1]);
	}
	int cnt;
	while(mini<maxi)
	{
		mid=mini+(maxi-mini)/2;
		cnt=0;
		for(i=0;i<n;i++)
		{
			j=search(A[i],mid)+1;
			cnt+=j;
		}
		if(cnt<med)
			mini=mid+1;
		else
			maxi=mid;
	}
	cout<<mini<<'\n';
	return 0;
}