#include<bits/stdc++.h>
using namespace std;
void swap(int* x,int* y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int parent(int i)
{
	return (i-1)/2;
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
void heapify(int* a,int i,int n)
{
	int lg=i;
	if(left(i)<n&&a[left(i)]>a[lg])
		lg=left(i);
	if(right(i)<n&&a[right(i)]>a[lg])
		lg=right(i);
	if(lg!=i)
	{
		swap(&a[lg],&a[i]);
		heapify(a,lg,n);
	}
}
int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	int lnl=n/2-1;
	for(i=lnl;i>=0;i--)
		heapify(a,i,n);
	for(i=n-1;i>0;i--)
	{
		swap(&a[0],&a[i]);
		heapify(a,0,i);
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}