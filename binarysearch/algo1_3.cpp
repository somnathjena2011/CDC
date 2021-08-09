#include<bits/stdc++.h>
using namespace std;
int Max_Cross_Seg(int a[],int n)
{
	int mid=(n-1)/2;
	int l,r,maxi;
	if(n&1)
	{
		l=mid-1;r=mid+1;maxi=a[mid];
	}
	else
	{
		l=mid-1;r=mid+2;maxi=a[mid]+a[mid+1];
	}
	int max_left=0;int max_right=0;
	int max_left_now=0;int max_right_now=0;
	while(l>=0)
	{
		max_left_now+=a[l];
		if(max_left_now>max_left)
			max_left=max_left_now;
		l--;
	}
	while(r<n)
	{
		max_right_now+=a[r];
		if(max_right_now>max_right)
			max_right=max_right_now;
		r++;
	}
	maxi+=(max_left+max_right);
	return maxi;
}
int Max_Seg(int a[],int n)
{
	if(n==1)
		return a[0];
	if(n==2)
		return max(a[0],max(a[1],a[0]+a[1]));
	int mid=(n+1)/2;
	int left_seg_max = Max_Seg(a,mid);
	int right_seg_max= Max_Seg(a+mid,n-mid);
	int cross_seg_max= Max_Cross_Seg(a,n);
	int max_val=max(left_seg_max,max(right_seg_max
		,cross_seg_max));
	return max_val;
}
int main()
{
	int n,i;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	int ans=Max_Seg(a,n);
	cout<<ans<<'\n';
	return 0;
}