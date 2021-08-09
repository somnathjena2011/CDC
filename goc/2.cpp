#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    ll t,n,i,j,c,d,b,p,x,y,z,w;
    cin>>n;
    cin>>c>>d;
    vector<pair<ll,ll>> coins,diams;
    for(i=0;i<n;i++)
    {
        cin>>b>>p>>t;
        if(t==0)
            coins.push_back({b,p});
        else
            diams.push_back({b,p});
    }
    sort(coins.begin(),coins.end());
    sort(diams.begin(),diams.end());
    ll c1=-1;ll c2=-1;ll d1=-1;ll d2=-1;
    ll cs=coins.size();ll ds=diams.size();
    for(i=cs-1;i>=0;i--)
    {
        if(coins[i].second<=c)
        {
            c1=coins[i].first;
            break;
        }
    }
    for(i=ds-1;i>=0;i--)
    {
        if(diams[i].second<=d)
        {
            d1=diams[i].first;
            break;
        }
    }
    ll coins1[c+1];ll diams1[d+1];
    ll coins2[c+1];ll diams2[d+1];
    for(i=0;i<=c;i++)
        coins1[i]=coins2[i]=-1;
    for(i=0;i<=d;i++)
        diams1[i]=diams2[i]=-1;
    for(i=0;i<cs;i++)
    {
        x=coins[i].first;
        y=coins[i].second;
        if(coins1[y]<0)
            coins1[y]=i;
        else if(x>=coins[coins1[y]].first)
        {
            coins2[y]=coins1[y];
            coins1[y]=i;
        }
        else if(coins2[y]<0||x>coins[coins2[y]].first)
            coins2[y]=i;
    }
    for(i=0;i<ds;i++)
    {
        x=diams[i].first;
        y=diams[i].second;
        if(diams1[y]<0)
            diams1[y]=i;
        else if(x>=diams[diams1[y]].first)
        {
            diams2[y]=diams1[y];
            diams1[y]=i;
        }
        else if(diams2[y]<0||x>diams[diams2[y]].first)
            diams2[y]=i;
    }
    for(i=1;i<=c;i++)
    {
        vector<pair<ll,ll>> v;
        if(coins1[i-1]>=0)v.push_back({coins[coins1[i-1]].first,coins1[i-1]});
        else v.push_back({-1,-1});
        if(coins2[i-1]>=0)v.push_back({coins[coins2[i-1]].first,coins2[i-1]});
        else v.push_back({-1,-1});
        if(coins1[i]>=0)v.push_back({coins[coins1[i]].first,coins1[i]});
        else v.push_back({-1,-1});
        if(coins2[i]>=0)v.push_back({coins[coins2[i]].first,coins2[i]});
        else v.push_back({-1,-1});
        sort(v.begin(),v.end());
        coins1[i]=v[3].second;
        coins2[i]=v[2].second;
    }
    for(i=1;i<=d;i++)
    {
        vector<pair<ll,ll>> v;
        if(diams1[i-1]>=0)v.push_back({diams[diams1[i-1]].first,diams1[i-1]});
        else v.push_back({-1,-1});
        if(diams2[i-1]>=0)v.push_back({diams[diams2[i-1]].first,diams2[i-1]});
        else v.push_back({-1,-1});
        if(diams1[i]>=0)v.push_back({diams[diams1[i]].first,diams1[i]});
        else v.push_back({-1,-1});
        if(diams2[i]>=0)v.push_back({diams[coins2[i]].first,diams2[i]});
        else v.push_back({-1,-1});
        sort(v.begin(),v.end());
        diams1[i]=v[3].second;
        diams2[i]=v[2].second;
    }
    for(i=cs-1;i>=0;i--)
    {
        x=coins[i].first;
        y=coins[i].second;
        if(y>=c)
            continue;
        z=c-y;
        if(coins1[z]>=0&&coins1[z]!=i)
            c2=max(c2,x+coins[coins1[z]].first);
        else if(coins2[z]<=0&&coins2[z]!=i)
            c2=max(c2,x+coins[coins2[z]].first);
    }
    for(i=ds-1;i>=0;i--)
    {
        x=diams[i].first;
        y=diams[i].second;
        if(y>=d)
            continue;
        z=d-y;
        if(diams1[z]>=0&&diams1[z]!=i)
            d2=max(d2,x+diams[diams1[z]].first);
        else if(diams2[z]>=0&&diams2[z]!=i)
            d2=max(d2,x+diams[diams2[z]].first);
    }
    if(c1<0)c1=0;
    if(d1<0)d1=0;
    if(c2<0)c2=0;
    if(d2<0)d2=0;
    ll ans=max({c1+d1,c2,d2});
    cout<<ans<<'\n';
    return 0;
}
