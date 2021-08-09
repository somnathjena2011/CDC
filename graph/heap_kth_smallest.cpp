#include<bits/stdc++.h>
using namespace std;
void swap(int* x,int* y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void maxHeapify(int* heap,int i,int k)
{
	int l=2*i+1;
	int r=2*i+2;
	int m=i;
	if(l<k&&heap[l]>heap[m])
		m=l;
	if(r<k&&heap[r]>heap[m])
		m=r;
	if(m!=i)
	{
		swap(&heap[i],&heap[m]);
		maxHeapify(heap,m,k);
	}
}
int main()
{
	int n,k,i;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	int last=k/2-1;
	for(i=last;i>=0;i--)
		maxHeapify(a,i,k);
	for(i=k;i<n;i++)
	{
		if(a[i]<a[0])
		{
			swap(&a[i],&a[0]);
			maxHeapify(a,0,k);
		}
	}
	cout<<a[0]<<'\n';
	return 0;
}