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
struct Set{
    int parent;
    int rank;
    int flip;
    Set(int p):parent(p),rank(0),flip(0){}
};
void Make(Set* sets[],int n)
{
    for(int i=1;i<=n;i++)
    {
        sets[i]=new Set(i);
    }
}
int Find(Set* sets[],int i,int &flip)
{
    if(sets[i]->parent!=i)
    {
        flip^=(sets[i]->flip);
        return(Find(sets,sets[i]->parent,flip));
    }
    flip^=(sets[i]->flip);
    return i;
}
void Union(Set* sets[],int x,int y,int flip)
{
    int cx,cy;
    int px=Find(sets,x,cx);
    int py=Find(sets,y,cy);
    if(sets[px]->rank < sets[py]->rank)
    {
        sets[px]->parent=py;
        sets[px]->flip^=flip;
    }
    else if(sets[py]->rank < sets[px]->rank)
    {
        sets[py]->parent=px;
        sets[py]->flip^=flip;
    }
    else
    {
        sets[py]->parent=px;
        sets[py]->flip^=flip;
        sets[px]->rank++;
    }
}
int main()
{
    int t,n,m,u,v,i,ans,f,pu,pv,cu,cv;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        Set* sets[n+1];
        for(i=1;i<=n;i++)
            sets[i]=NULL;
        Make(sets,n);
        ans=0;f=0;
        for(i=1;i<=m;i++)
        {
            cin>>u>>v;
            if(f)
                continue;
            cu=0;cv=0;
            pu=Find(sets,u,cu);
            pv=Find(sets,v,cv);
            //cout<<"pu="<<pu<<" pv="<<pv<<'\n';
            //cout<<"cu="<<cu<<" cv="<<cv<<'\n';
            if(pu==pv)
            {
                if(cu==cv)
                    f=1;
                else
                    ++ans;
            }
            else
            {
                if(cu!=cv)
                {
                    ++ans;
                    Union(sets,pu,pv,0);
                }
                else
                {
                    ++ans;
                    Union(sets,pu,pv,1);
                }
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}