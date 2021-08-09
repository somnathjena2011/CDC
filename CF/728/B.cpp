#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
ll ind[200005];
ll a[100005];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t,n,i,j,ma,mi,ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=2*n;i++)
            ind[i]=0;
        for(i=1;i<=n;i++)
        {
            cin>>a[i];
            ind[a[i]]=i;
        }
        ma=2*n-1;
        mi=3;ans=0;
        for(i=1;i*i<=2*n;i++)
        {
            if(!ind[i])
                continue;
            for(j=i+1;i*j<=ma;j++)
            {
                if(!ind[j])
                    continue;
                if(i*j<mi)
                    continue;
                if(i*j>ma)
                    break;
                if(ind[i]+ind[j]==i*j)
                    ++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}