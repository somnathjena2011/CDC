/*
Time=O(n2)
Space=O(1)
Inplace
Stable
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,val;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=1;i<n;i++)
	{
		val=a[i];
		for(j=i-1;j>=0;j--)
		{
			if(a[j]>val)
				a[j+1]=a[j];
			else
				break;
		}
		a[j+1]=val;
	}
	for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
}