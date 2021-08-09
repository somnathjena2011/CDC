#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,v,e,i,j,u,x,y,w,c,l,n,ans;
	cin>>t;
	for(c=1;c<=t;c++)
	{
		cin>>v>>e; 
		vector<pair<int,pair<int,int>>> edges;
		for(i=0;i<e;i++)
		{
			cin>>x>>y>>w;
			edges.push_back({w,{min(x-1,y-1),max(x-1,y-1)}});
		}
		sort(edges.begin(),edges.end());
		int d[v],r[v],f[v];
		int done[v]={0};
		for(i=0;i<v;i++)
			d[i]=INT_MAX;
		for(i=0;i<e;i++)
		{
			w=edges[i].first;
			x=edges[i].second.first;
			y=edges[i].second.second;
			if(w<d[x])
			{
				d[x]=w;
				r[x]=i;
				f[x]=y;
			}
			if(w<d[y])
			{
				d[y]=w;
				r[y]=i;
				f[y]=x;
			}
		}
		set<int> st;
		vector<pair<int,int>> sorted;
		for(i=0;i<v;i++)
			sorted.push_back({d[i],i});
		sort(sorted.begin(),sorted.end());
		for(i=0;i<v;i++)
		{
			u=sorted[i].second;
			if(!done[f[u]])
			{
				st.insert(u);
				done[u]=1;
			}
			else
				done[u]=1;
		}
		for(i=0;i<v;i++)
		{
			if(d[i]>0&&d[f[i]]==0)
				st.insert(i);
		}
		n=st.size();
		ans=(1<<n);
		cout<<"Case #"<<c<<": "<<ans<<'\n';
	}
	return 0;
}