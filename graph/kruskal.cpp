#include<bits/stdc++.h>
using namespace std;
int Find(pair<int,int> sets[],int i)
{
	if(sets[i].first==i)
		return i;
	int fset=Find(sets,sets[i].first);
	sets[i].first=fset;
	return sets[i].first;
}
void Union(pair<int,int> sets[],int x,int y)
{
	int xset=Find(sets,x);
	int yset=Find(sets,y);
	if(sets[xset].second<sets[yset].second)
		sets[xset].first=yset;
	else if(sets[yset].second<sets[xset].second)
		sets[yset].first=xset;
	else
	{
		int rank=sets[xset].second;
		sets[yset].first=xset;
		sets[xset].second=rank+1;
	}
}
int main()
{
	int v,e;
	int i,j,x,y,w,u,xset,yset;
	int ans=0;
	vector<pair<int,pair<int,int>>> edges;
	vector<int> mst;
	cin>>v>>e;
	for(i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		edges.push_back({w,{x,y}});
	}
	sort(edges.begin(),edges.end());
	pair<int,int> sets[v];
	for(i=0;i<v;i++)
		sets[i]={i,0};
	for(i=0;i<e;i++)
	{
		x=edges[i].second.first;
		y=edges[i].second.second;
		xset=Find(sets,x);
		yset=Find(sets,y);
		if(xset!=yset)
		{
			ans+=edges[i].first;
			mst.push_back(i);
			Union(sets,x,y);
		}
	}
	cout<<"minWt="<<ans<<'\n';
	cout<<"Edges:\n";
	for(auto ind:mst)
		cout<<edges[ind].second.first<<' '<<edges[ind].second.second<<'\n';
	return 0;
}