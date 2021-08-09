#include<bits/stdc++.h>
using namespace std;
//O(n) to build the heap
void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
void heapify(int* heap,int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int s=i;
	if(l<n&&heap[l]>heap[s])
		s=l;
	if(r<n&&heap[r]>heap[s])
		s=r;
	if(s!=i)
	{
		swap(&heap[i],&heap[s]);
		heapify(heap,s,n);
	}
}
int main()
{
	int n;
	cin>>n;
	int i;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	int lastNonLeaf=n/2-1;
	for(i=lastNonLeaf;i>=0;i--)
		heapify(a,i,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}