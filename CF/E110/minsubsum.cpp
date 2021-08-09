#include<bits/stdc++.h>
using namespace std;
int minSubArrayLen(int target, vector<int>& nums) {
    int n=nums.size();
    if(n==1)
        return nums[0]>=target?1:0;
    int i,j;
    long sum=0;
    int ans=n+1;
    i=0;j=0;
    while(i<=j&&j<n)
    {
        while(sum+(long)nums[j]>=target)
        {
            cout<<"sum="<<sum<<" sum+a[j]="<<sum+(long)nums[j]<<'\n';
            ans=min(ans,j-i+1);
            if(i+1>j)
                break;
            else
            {
                sum-=(long)nums[i];
                i++;
            }
        }
        sum+=(long)nums[j];
        j++;
    }
    return ans==n+1?0:ans;
}
int main()
{
    int n,t;
    cin>>n>>t;
    int i;
    vector<int> v(n);
    for(i=0;i<n;i++)
        cin>>v[i];
    cout<<minSubArrayLen(t,v)<<'\n';
    return 0;
}