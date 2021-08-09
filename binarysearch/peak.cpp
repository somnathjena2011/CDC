#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	//All adjacent elements must be unique
	//assume left of A[0]=-inf and right of A[n-1]=-inf
	vector<int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	int s=0;int e=n-1;int m;int prev,next;
	while(s<=e)
	{
		m=s+(e-s)/2;
		prev=m-1>=0?A[m-1]:INT_MIN;
		next=m+1<n ?A[m+1]:INT_MIN;
		if(prev<A[m]&&next<A[m])
		{
			cout<<m<<'\n';
			return 0;
		}
		if(prev<A[m]&&A[m]<next)
			s=m+1;
		else
			e=m-1;
	}
	cout<<e<<'\n';
	return 0;
}