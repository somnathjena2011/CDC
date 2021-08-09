#include<bits/stdc++.h>
using namespace std;
void heapify(int* a,int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int lg=i;
	if(l<n&&a[l]>=a[lg])
		lg=l;
	if(r<n&&a[r]>=a[lg])
		lg=r;
	if(lg!=i)
	{
		swap(a[lg],a[i]);
		heapify(a,lg,n);
	}
}
int main()
{
	int n,k,i;
	cin>>n>>k;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=k/2-1;i>=0;i--)
		heapify(a,i,k);
	for(i=k;i<n;i++)
	{
		if(a[i]<a[0])
		{
			swap(a[0],a[i]);
			heapify(a,0,k);
		}
	}
	cout<<a[0]<<'\n';
}