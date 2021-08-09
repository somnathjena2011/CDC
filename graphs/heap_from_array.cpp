#include<bits/stdc++.h>
using namespace std;
void swap(int* x,int* y)
{
	int t=*x;
	*x=*y;
	*y=t;
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
	int sm=i;
	if(left(i)<n&&a[left(i)]<a[sm])
		sm=left(i);
	if(right(i)<n&&a[right(i)]<a[sm])
		sm=right(i);
	if(sm!=i)
	{
		swap(&a[sm],&a[i]);
		heapify(a,sm,n);
	}
}
int main()
{
	int n,i;
	cin>>n;
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