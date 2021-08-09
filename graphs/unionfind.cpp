#include<bits/stdc++.h>
using namespace std;
struct Set{
	int parent;
	int rank;
	Set(int p):parent(p),rank(0){}
};
int Find(Set* sets[],int i)
{
	if(sets[i]->parent!=i)
		sets[i]->parent=Find(sets,sets[i]->parent);
	return sets[i]->parent;
}
void Union(Set* sets[],int x,int y)
{
	int px=Find(sets,x);
	int py=Find(sets,y);
	if(sets[px]->rank<sets[py]->parent)
		sets[px]->parent=py;
	else if(sets[py]->rank<sets[px]->parent)
		sets[py]->parent=px;
	else
	{
		sets[px]->parent=py;
		++sets[py]->rank;
	}
}
bool isCycle(vector<pair<int,int>>& edges,int n)
{
	Set* sets[n];
	for(int i=0;i<n;i++)
		sets[i]=new Set(i);
	int u,v,pu,pv;
	for(auto edge:edges)
	{
		u=edge.first;
		v=edge.second;
		pu=Find(sets,u);
		pv=Find(sets,v);
		if(pu==pv)
			return true;
		Union(sets,u,v);
	}
	return false;
}
int main()
{
	int n,e;
	cin>>n>>e;
	vector<pair<int,int>> edges;
	int u,v;
	for(int i=0;i<e;i++)
	{
		cin>>u>>v;
		edges.push_back({u,v});
	}
	cout<<isCycle(edges,n)<<'\n';
	return 0;
}