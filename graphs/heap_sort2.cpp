//in-place
//un-stable
#include<bits/stdc++.h>
using namespace std;
void heapify(int* a,int i,int n)
{
	int l=2*i+1;
	int r=2*i+2;
	int lg=i;
	if(l<n&&a[l]>a[lg])
		lg=l;
	if(r<n&&a[r]>a[lg])
		lg=r;
	if(lg!=i)
	{
		swap(a[i],a[lg]);
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
	for(i=0;i<n;i++)
	{
		swap(a[0],a[n-i-1]);
		heapify(a,0,n-i-1);
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}