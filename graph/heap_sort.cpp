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
int parent(int i)
{
	return (i-1)/2;
}
int swap(int* x,int* y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
int main()
{
	int n;
	cin>>n;
	int arr[n];
	int i,j;
	for(i=0;i<n;i++)
		cin>>arr[i];
	int p,c;
	for(i=1;i<n;i++)
	{
		c=i;
		while(c!=0&&arr[parent(c)]<arr[c])
		{
			swap(&arr[c],&arr[parent(c)]);
			c=parent(c);
		}
	}
	int size;int lg;
	for(size=n-1;size>0;size--)
	{
		swap(&arr[0],&arr[size]);
		p=0;
		while(1)
		{
			lg=p;
			if(left(p)<size&&arr[left(p)]>arr[lg])
				lg=left(p);
			if(right(p)<size&&arr[right(p)]>arr[lg])
				lg=right(p);
			if(lg==p)
				break;
			swap(&arr[lg],&arr[p]);
			p=lg;
		}
	}
	for(i=0;i<n;i++)
		cout<<arr[i]<<' ';
	cout<<'\n';
	return 0;
}