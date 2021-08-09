#include<bits/stdc++.h>
using namespace std;
unsigned long long solve(unsigned long long x,unsigned long long d)
{
    unsigned long long s=2;unsigned long long e=(unsigned long long)pow((double)x,1.0/d);
    unsigned long long m;
    unsigned long long p,i;
    unsigned long long sum;
    while(s<=e)
    {
        m=s+(e-s)/2;
        p=1;sum=1;
        // if(d==46||d==47||d==48)
        // cout<<"m="<<m<<'\n';
        for(i=1;i<d;i++)
        {
            p*=m;
            sum+=p;
            if(sum>x)
                break;
        }
        // if(d==46||d==47||d==48)
        // cout<<"p="<<p<<'\n';
        // if(d==46||d==47||d==48)
        // cout<<"sum="<<sum<<'\n';
        if(sum==x)
            return m;
        else if(sum<x)
            s=m+1;
        else
            e=m-1;
    }
    return x;
}
string smallestGoodBase(string n) {
    unsigned long long x=0;
    unsigned long long l=n.length();
    unsigned long long i;
    for(i=0;i<l;i++)
        x=x*10+(n[i]-'0');
    unsigned long long lg=0;
    unsigned long long y=x;
    while(y>>=1)
        ++lg;
    unsigned long long ans=x-1;
    unsigned long long res;
    for(i=2;i<=lg+1;i++)
    {
        res=solve(x,i);
        if(res>0)
            ans=min(ans,res);
    }
    string str="";
    while(ans)
    {
        i=ans%10;
        str=(char)(i+'0')+str;
        ans/=10;
    }
    return str;
}
int main()
{
    cout<<smallestGoodBase("13")<<'\n';
    return 0;
}