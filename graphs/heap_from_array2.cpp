#include<bits/stdc++.h>
using namespace std;
void heapify(int* a,int i,int n)
{
	int s=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n&&a[l]<a[s])
		s=l;
	if(r<n&&a[r]<a[s])
		s=r;
	if(s!=i)
	{
		swap(a[i],a[s]);
		heapify(a,s,n);
	}
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	int lastNonLeaf=n/2-1;
	for(int i=lastNonLeaf;i>=0;i--)
		heapify(a,i,n);
	for(int i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}