#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll s[500005];
ll pre[500005];
ll odc[500005];
int main()
{
    ll t,c,x,i,j,n,o,d,x1,x2,a,b,m,l,cc;
    ll sum,oc,curr,od,ans;
    cin>>t;
    for(cc=1;cc<=t;cc++)
    {
        cin>>n>>o>>d;
        cin>>x1>>x2>>a>>b>>c>>m>>l;
        if(l==0&&d<0)
        {
            cout<<"Case #"<<cc<<": IMPOSSIBLE\n";
            continue;
        }
        s[0]=x1+l;
        s[1]=x2+l;
        pre[0]=s[0];pre[1]=s[0]+s[1];
        if(s[0]%2==1)odc[0]=1; 
        else odc[0]=0;
        if(s[1]%2==1)odc[1]=odc[0]+1;
        else odc[1]=odc[0];
        for(i=2;i<n;i++)
        {
            x=((a*(s[i-1]-l)+b*(s[i-2]-l))+c+m)%m;
            s[i]=x+l;
            pre[i]=pre[i-1]+s[i];
            if(s[i]%2==1)odc[i]=odc[i-1]+1;
            else odc[i]=odc[i-1];
        }
        i=0;
        j=0;
        sum=0;
        oc=0;
        curr=0;
        od=0;
        ans=LONG_MIN;
        while(i<=j&&i<n&&j<n)
        {
            od=odc[j]-(i==0?0:odc[i-1]);
            sum=pre[j]-(i==0?0:pre[i-1]);
            if(od>o)
            {
                while(s[i]%2==0&&i<j)
                i++;
                i++;
                if(i>j)
                j=i;
            }
            else if(sum>d)
            {
                while(i<=j&&(pre[j]-(i==0?0:pre[i-1]))>d)
                i++;
                if(i>j)
                j=i;
            }
            else if(sum<0)
            {
                j=i+1;
                i=j;
            }
            else
            {
                if(sum<=d&&od<=o&&sum>ans)
                ans=sum;
                j++;
            }
        }
        if(ans==LONG_MIN)
        cout<<"Case #"<<cc<<": IMPOSSIBLE\n";
        else
        cout<<"Case #"<<cc<<": "<<ans<<'\n';
    }
    return 0;
}