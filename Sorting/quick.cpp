#include<bits/stdc++.h>
using namespace std;
void swap(int* a,int* b)
{
	int t=*a;
	*a=*b;
	*b=t;
}
int partition(int a[],int s,int e)
{
	int p=s;
	int i;
	int val=a[e];
	for(i=s;i<e;i++)
	{
		if(a[i]<=val)
		{
			swap(a+p,a+i);
			p++;
		}
	}
	swap(a+p,a+e);
	return p;
}
void sort(int a[],int s,int e)
{
	if(s>=e)
		return;
	int p=partition(a,s,e);
	sort(a,s,p-1);
	sort(a,p+1,e);
}
int main()
{
	int n,i,j;
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