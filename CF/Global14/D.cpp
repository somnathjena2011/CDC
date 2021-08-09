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
#define rloop0(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>0;i--)
#define sloop0(i,n,s) for(i=0;i<n;i+=s)
int lft[200005],rgt[200005];
int main()
{
	int t,n,c,i,j,l,r,m,s;
	int lt,rt;
	cin>>t;
	int ans=0;
	while(t--)
	{
		cin>>n>>l>>r;
		loop0(i,n)
		lft[i]=rgt[i]=0;
		loop0(i,l)
		{
			cin>>c;
			++lft[c];
		}
		loop0(i,r)
		{
			cin>>c;
			++rgt[c];
		}
		set<pair<int,int>,greater<pair<int,int>>> oddl,oddr;
		loop1(i,n)
		{
			if(s!=0)
			{
				if(lft[i]>rgt[i])
					oddl.insert(mp(lft[i]-rgt[i],i));
				else if(rgt[i]>lft[i])
					oddr.insert(mp(rgt[i]-lft[i],i));
			}
		}
		loop1(i,n)
		{
			s=lft[i]-rgt[i];
			if(s!=0)
			{
				if(lft[i]>rgt[i])
				{
					auto it=oddr.begin();
					while(it!=oddr.end()&&lft[i]>rgt[i])
					{
						lt=it->ss;
						m=min(lft[i]-rgt[i],rgt[it->ss]-lft[it->ss]);
						oddl.erase(oddl.find(mp(lft[i]-rgt[i],i)));
						oddr.erase(it);
						lft[i]-=m;
						lft[lt]+=m;
						ans+=m;
						if(lft[lt]!=rgt[lt])
							oddr.insert(mp(rgt[lt]-lft[lt],lt));
						if(lft[i]!=rgt[i])
							oddl.insert(mp(lft[i]-rgt[i],i));
						it=oddr.begin();
					}
					if((lft[i]-rgt[i])%2==0)
					{
						oddl.erase(oddl.find(mp(lft[i]-rgt[i],i)));
						ans+=((lft[i]-rgt[i]));
					}
					else
					{
						oddl.erase(oddl.find(mp(lft[i]-rgt[i],i)));
						it=oddl.begin();
						lt=it->ss;
						oddl.erase(it);
						++ans;--lft[i];++lft[lt];
						oddl.insert(mp(lft[lt]-rgt[lt],lt));
					}
				}
				else
				{
					auto it=oddl.begin();
					while(it!=oddl.end()&&rgt[i]>lft[i])
					{
						lt=it->ss;
						m=min(rgt[i]-lft[i],lft[it->ss]-rgt[it->ss]);
						oddr.erase(oddl.find(mp(rgt[i]-lft[i],i)));
						oddl.erase(it);
						rgt[i]-=m;
						rgt[lt]+=m;
						ans+=m;
						if(lft[lt]!=rgt[lt])
							oddl.insert(mp(lft[lt]-rgt[lt],lt));
						if(lft[i]!=rgt[i])
							oddr.insert(mp(rgt[i]-lft[i],i));
						it=oddl.begin();
					}
					if((rgt[i]-lft[i])%2==0)
					{
						oddr.erase(oddr.find(mp(rgt[i]-lft[i],i)));
						ans+=((rgt[i]-lft[i]));
					}
					else
					{
						oddr.erase(oddr.find(mp(rgt[i]-lft[i],i)));
						it=oddr.begin();
						lt=it->ss;
						oddr.erase(it);
						++ans;--rgt[i];++rgt[lt];
						oddr.insert(mp(rgt[lt]-lft[lt],lt));
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}