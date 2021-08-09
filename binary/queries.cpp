// #include<bits/stdc++.h>
// using namespace std;
// long long mod = 1e9+7;
// long long power(long long x,long long y)
// {
//     long long ans=1;
//     while(y)
//     {
//         if(y&1)
//         ans=(ans*x)%mod;
//         x=(x*x)%mod;
//         y>>=1;
//     }
//     return ans;
// }
// long long divisors(long long n)
// {
//     long long ans=1;long long c=0;long long x=n;
//     for(long long i=2;i*i<=x;i++)
//     {
//         if(x%i==0)
//         {
//             c=0;
//             while(x%i==0)
//             {
//                 ++c;
//                 x/=i;
//             }
//             ans*=c;
//         }
//     }
//     if(x>1)
//     ans*=2;
//     return ans;
// }
// long long prod(long long n)
// {
//     long long d=divisors(n);
//     cout<<n<<' '<<d<<'\n';
//     if(d%2==0)
//     return power(n,d/2);
//     long long s=(long long)sqrt(n);
//     return (power(n,d/2)*s)%mod;
// }
// long long search(vector<pair<long long,long long>>& v,long long k)
// {
//     long long n=v.size();
//     long long s=0;long long e=n-1;long long m;
//     long long ans=-1;
//     while(s<=e)
//     {
//         m=s+(e-s)/2;
//         if(v[m].second<k)
//         s=m+1;
//         else
//         {
//             ans=v[m].first;
//             e=m-1;
//         }
//     }
//     return ans;
// }
// vector<int> solve(vector<int> &A, vector<int> &B) {
//     long long n=A.size();
//     long long nge[n];
//     long long pge[n];
//     long long i,j;
//     nge[n-1]=n;
//     pge[0]=-1;
//     for(i=n-2;i>=0;i--)
//     {
//         j=i+1;
//         while(j<n&&A[j]<=A[i])
//         j=nge[j];
//         nge[i]=j;
//     }
//     for(i=1;i<n;i++)
//     {
//         j=i-1;
//         while(j>=0&&A[j]<A[i])
//         j=pge[j];
//         pge[i]=j;
//     }
//     long long prods[n];
//     long long maxis[n];
//     for(i=0;i<n;i++)
//     {
//         prods[i]=prod((long long)A[i]);
//         maxis[i]=0;
//     }
//     for(i=0;i<n;i++)
//         cout<<prods[i]<<' ';
//     cout<<'\n';
//     long long l,r,x,y,z;
//     for(i=0;i<n;i++)
//     {
//         l=pge[i];
//         r=nge[i];
//         x=i-l+1;
//         y=r-i+1;
//         z=x+y+1;
//         maxis[i]=(z*(z+1))/2-(x*(x+1))/2-(y*(y+1))/2;
//     }
//     map<long long,long long,greater<long long>> mp;
//     for(i=0;i<n;i++)
//     mp[prods[i]]+=maxis[i];
//     vector<pair<long long,long long>> v;
//     for(auto pr:mp)
//     v.push_back(pr);
//     n=v.size();
//     for(i=1;i<n;i++)
//     v[i]={v[i].first,v[i-1].second+v[i].second};
//     n=B.size();
//     vector<int> ans;
//     for(i=0;i<n;i++)
//     ans.push_back((int)search(v,(long long)B[i]));
//     return ans;
// }
// int main()
// {
//     vector<int> v={39,99,70,24,49};
//     vector<int> q={2,4,6,8,10};
//     vector<int> ans=solve(v,q);
//     return 0;
// }
long long mod = 1e9+7;
long long power(long long x,long long y)
{
    long long ans=1;
    while(y)
    {
        if(y&1)
        ans=(ans*x)%mod;
        x=(x*x)%mod;
        y>>=1;
    }
    return ans;
}
long long divisors(long long n)
{
    long long ans=1;long long c=0;long long x=n;
    for(long long i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            c=0;
            while(x%i==0)
            {
                ++c;
                x/=i;
            }
            ans*=(c+1);
        }
    }
    if(x>1)
    ans*=2;
    return ans;
}
long long prod(long long n)
{
    long long d=divisors(n);
    if(d%2==0)
    return power(n,d/2);
    long long s=(long long)sqrt(n);
    return (power(n,d/2)*s)%mod;
}
long long search(vector<pair<long long,long long>>& v,long long k)
{
    long long n=v.size();
    long long s=0;long long e=n-1;long long m;
    long long ans=-1;
    while(s<=e)
    {
        m=s+(e-s)/2;
        if(v[m].second<k)
        s=m+1;
        else
        {
            ans=v[m].first;
            e=m-1;
        }
    }
    return ans;
}
vector<int> Solution::solve(vector<int> &A, vector<int> &B) {
    long long n=A.size();
    long long nge[n];
    long long pge[n];
    long long i,j;
    nge[n-1]=n;
    pge[0]=-1;
    for(i=n-2;i>=0;i--)
    {
        j=i+1;
        while(j<n&&A[j]<=A[i])
        j=nge[j];
        nge[i]=j;
    }
    for(i=1;i<n;i++)
    {
        j=i-1;
        while(j>=0&&A[j]<A[i])
        j=pge[j];
        pge[i]=j;
    }
    long long prods[n];
    long long maxis[n];
    for(i=0;i<n;i++)
    {
        prods[i]=prod((long long)A[i]);
        maxis[i]=0;
    }
    long long l,r,x,y,z;
    for(i=0;i<n;i++)
    {
        l=pge[i];
        r=nge[i];
        x=i-l+1;
        y=r-i+1;
        z=x+y+1;
        maxis[i]=(z*(z+1))/2-(x*(x+1))/2-(y*(y+1))/2;
    }
    map<long long,long long,greater<long long>> mp;
    for(i=0;i<n;i++)
    mp[prods[i]]+=maxis[i];
    vector<pair<long long,long long>> v;
    for(auto pr:mp)
    v.push_back(pr);
    n=v.size();
    for(i=1;i<n;i++)
    v[i]={v[i].first,v[i-1].second+v[i].second};
    n=B.size();
    vector<int> ans;
    for(i=0;i<n;i++)
    ans.push_back((int)search(v,(long long)B[i]));
    return ans;
}