#include<bits/stdc++.h>
using namespace std;
int pivot(vector<int>& A)
{
	int n=A.size();
	if(n==1)
		return A[0];
	int s=0;int e=n-1;int m;
	while(s<=e)
	{
		if(s==e)
			return A[s];
		m=s+(e-s)/2;
		if(A[s]==A[m]&&A[m]==A[e])
		{
			s++;e--;
			continue;
		}
		if(A[s]<A[e])
			return A[s];
		if(A[m]<A[m-1])
			return A[m];
		if(A[m]<=A[e])
			e=m-1;
		else
			s=m+1;
	}
	return A[e];
}
int main()
{
	int n,i;
	cin>>n;
	vector<int> v(n);
	for(i=0;i<n;i++)
		cin>>v[i];
	cout<<pivot(v)<<'\n';
	return 0;
}