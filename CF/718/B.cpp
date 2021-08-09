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
int n,m;
int b[102][102];
int used[102][102];
int main()
{
	int t,i,j,k,l;
	cin>>t;
	while(t--)
	{
		cin>>n>>m;
		vector<pair<int,pair<int,int>>> paths;
		vector<vector<pair<int,int>>> ans;
		vector<vector<pair<int,int>>> pts;
		loop0(i,n)
		{
			vector<pair<int,int>> pt;
			loop0(j,m)
			{
				cin>>b[i][j];
				used[i][j]=0;
				paths.pb(mp(b[i][j],mp(i,j)));
				pt.pb(mp(b[i][j],j));
			}
			pts.pb(pt);
		}
		loop0(i,n)
		sort(pts[i].begin(),pts[i].end());
		sort(paths.begin(),paths.end());
		loop0(i,m)
		{
			for(auto p:paths)
			{
				if(!used[p.ss.ff][p.ss.ss])
				{
					vector<pair<int,int>> v;
					k=p.ss.ff;
					v.pb(mp(b[p.ss.ff][p.ss.ss],k));
					used[p.ss.ff][p.ss.ss]=1;
					for(j=0;j<n;j++)
					{
						if(j==k)continue;
						l=pts[j].back().ff;
						v.pb(mp(b[j][pts[j].back().ss],j));
						used[j][pts[j].back().ss]=1;
						pts[j].pop_back();
					}
					sort(v.begin(),v.end(),[](pair<int,int> p1,pair<int,int> p2){
						if(p1.ss<p2.ss)
							return true;
						return false;
					});
					ans.pb(v);
					break;
				}
			}
		}
		loop0(i,n)
		{
			loop0(j,m)
			{
				cout<<ans[j][i].ff<<' ';
			}
			cout<<'\n';
		}
	}
	return 0;
}