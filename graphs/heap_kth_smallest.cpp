#include<bits/stdc++.h>
using namespace std;
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
void swap(int* x,int* y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
void heapify(int* a,int i,int k)
{
	int lg=i;
	if(left(i)<k&&a[left(i)]>a[lg])
		lg=left(i);
	if(right(i)<k&&a[right(i)]>a[lg])
		lg=right(i);
	if(lg!=i)
	{
		swap(&a[lg],&a[i]);
		heapify(a,lg,k);
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
		heapify(a,i,k);
	for(i=k;i<n;i++)
	{
		if(a[i]<a[0])
		{
			swap(&a[i],&a[0]);
			heapify(a,0,k);
		}
	}
	cout<<a[0]<<'\n';
	return 0;
}