#include<bits/stdc++.h>
using namespace std;
int findMedian(int* a,int n)
{
	sort(a,a+n);
	return *(a+n/2);
}
int partition(int* a,int s,int e,int p)
{
	int i;
	for(i=s;i<=e;i++)
		if(a[i]==p)
			break;
	int pivot=s;
	swap(a[i],a[e]);
	for(i=s;i<e;i++)
	{
		if(a[i]<=p)
		{
			swap(a[pivot],a[i]);
			pivot++;
		}
	}
	swap(a[pivot],a[e]);
	return pivot;
}
int kthSmallest(int* a,int s,int e,int k)
{
	int n=e-s+1;
	if(k>n)
		return INT_MAX;
	if(n<5)
	{
		sort(a+s,a+s+n);
		return *(a+s+k-1);
	}
	int groups=(n+4)/5;
	int median[groups];
	int i;
	for(i=0;i<groups-1;i++)
		median[i]=findMedian(a+i*5,5);
	median[i]=findMedian(a+i*5,n-i*5);
	int medOfMed=kthSmallest(median,0,groups-1,groups/2);
	int pivot=partition(a,s,e,medOfMed);
	if(pivot-s+1==k)
		return a[pivot];
	if(pivot-s+1>k)
		return kthSmallest(a,s,pivot-1,k);
	return kthSmallest(a,pivot+1,e,k-(pivot-s+1));
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