#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int s,int e)
{
	int p=s;int pivot=a[e];
	for(int i=s;i<e;i++)
	{
		if(a[i]<=pivot)
		{
			swap(a[i],a[p]);
			++p;
		}
	}
	swap(a[p],a[e]);
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
	int a[7]={2,3,4,5,6,7,1};
	sort(a,0,6);
	for(int i=0;i<7;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}