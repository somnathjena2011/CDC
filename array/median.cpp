#include<bits/stdc++.h>
using namespace std;
int findMedian(int* a,int n)
{
	sort(a,a+n);
	return a[n/2];
}
int partition(int* a,int s,int e,int pivot)
{
	int i;
	for(i=s;i<=e;i++)
		if(a[i]==pivot)
			break;
	swap(a[i],a[e]);
	int p=s;
	for(i=s;i<e;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[p],a[i]);
			p++;
		}
	}
	swap(a[p],a[e]);
	return p;
}
int kthSmallest(int* a,int s,int e,int k)
{
	if(s<=e)
	{
		int n=e-s+1;
		int i;
		int median[(n+4)/5];
		int groups=(n+4)/5;
		for(i=0;i<groups-1;i++)
			median[i]=findMedian(a+i*5,5);
		median[i]=findMedian(a+i*5,n-i*5);
		int medOfMed=kthSmallest(median,0,groups-1,groups/2);
		int pivot=partition(a,0,groups-1,medOfMed);
		if(pivot-s+1==k)
			return a[pivot];
		if(pivot-s+1>k)
			return kthSmallest(a,s,pivot-1,k);
		return kthSmallest(a,pivot+1,e,k-pivot+s-1);
	}
	return INT_MAX;
}
int main()
{
	int n,k,i;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cout<<kthSmallest(a,0,n-1,k)<<'\n';
	return 0;
}