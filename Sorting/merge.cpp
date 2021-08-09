/*
Time=O(nlogn)
Space=O(n)
Not inplace
Stable
Disadv=> performs all steps even if array sorted
*/
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int s,int m,int e)
{
	int t[e-s+1];
	int i,j,k;
	i=s;j=m+1;k=0;
	while(i<=m&&j<=e)
	{
		if(a[i]<=a[j])
		{
			t[k]=a[i];
			k++;i++;
		}
		else
		{
			t[k]=a[j];
			k++;j++;
		}
	}
	while(i<=m)
	{
		t[k]=a[i];
		k++;i++;
	}
	while(j<=e)
	{
		t[k]=a[j];
		k++;j++;
	}
	for(i=s;i<=e;i++)
		a[i]=t[i-s];
}
void sort(int a[],int s,int e)
{
	if(s>=e)
		return;
	int m=(s+e)/2;
	sort(a,s,m);
	sort(a,m+1,e);
	merge(a,s,m,e);
}
int main()
{
	int n,i,j,val;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,0,n-1);
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}