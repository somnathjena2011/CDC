#include<bits/stdc++.h>
using namespace std;
int getsum(int tree[],int i)
{
	i=i+1;
	int ans=0;
	while(i)
	{
		ans+=tree[i];
		i-=(i&(-i));
	}
	return ans;
}
void update(int tree[],int i,int n,int val)
{
	i=i+1;
	while(i<=n)
	{
		tree[i]+=val;
		i+=(i&(-i));
	}
}
int main()
{
	int arr[]={2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
	int n=12;
	int tree[13]={0};
	for(int i=0;i<n;i++)
		update(tree,i,n,arr[i]);
	cout<<getsum(tree,5)<<'\n';
	arr[3]+=6;
	update(tree,3,n,6);
	cout<<getsum(tree,2)<<'\n';
	return 0;
}