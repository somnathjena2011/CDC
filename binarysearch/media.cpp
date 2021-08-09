#include<bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
    int n=nums1.size();
    int m=nums2.size();
    if(n>m)
        return findMedianSortedArrays(nums2,nums1);
    int s=0;//min no of elements from start of first array
    int e=n;//max no of elements from start of first array
    int mid;int i,j;
    int mini,maxi,minj,maxj,l,r;
    int req=(n+m+1)/2;
    while(s<=e)
    {
        mid=s+(e-s)/2;
        i=mid-1;j=req-mid-1;
        mini=i>=0?nums1[i]:INT_MIN;
        minj=j>=0?nums2[j]:INT_MIN;
        maxi=i+1<n?nums1[i+1]:INT_MAX;
        maxj=j+1<m?nums2[j+1]:INT_MAX;
        l=max(mini,minj);
        r=min(maxi,maxj);
        if(l<=r)
        {
            if((n+m)&1)
                return (double)l;
            else
                return (double)(l+r)/2;
        }
        else if(l==mini)
            e=mid-1;
        else
            s=mid+1;
    }
}
int main()
{
    int n,m,i;
    cin>>n>>m;
    vector<int> v1(n),v2(m);
    for(i=0;i<n;i++)
        cin>>v1[i];
    for(i=0;i<m;i++)
        cin>>v2[i];
    double ans=findMedianSortedArrays(v1,v2);
    cout<<ans<<'\n';
    return 0;
}