#include<bits/stdc++.h>
using namespace std;
struct Set{
	int parent;
	int rank;
	int flip;
	Set(int p):parent(p),rank(0),flip(0){}
};
int Find(Set* sets[],int i,int& color)
{
	if(sets[i]->parent!=i)
	{
		color^=sets[i]->flip;
		return Find(sets,sets[i]->parent,color);
	}
	color^=sets[i]->flip;
	return sets[i]->parent;
}
void Union(Set* sets[],int x,int y,int flip)
{
	int cx,cy;
	int px=Find(sets,x,cx);
	int py=Find(sets,y,cy);
	if(sets[px]->rank<sets[py]->parent)
	{
		sets[px]->flip^=flip;
		sets[px]->parent=py;
	}
	else if(sets[py]->rank<sets[px]->parent)
	{
		sets[py]->flip^=flip;
		sets[py]->parent=px;
	}
	else
	{
		sets[px]->flip^=flip;
		sets[px]->parent=py;
		++sets[py]->rank;
	}
}
int main()
{
	int t,n,m;
	cin>>t;
	int ans=0;
	int i,u,v,pu,pv,cu,cv,f;
	while(t--)
	{
		cin>>n>>m;
		Set* sets[n+1];
		for(i=0;i<=n;i++)
			sets[i]=new Set(i);
		f=0;ans=0;
		for(i=0;i<m;i++)
		{
			cin>>u>>v;
			if(f)
				continue;
			cu=0;cv=0;
			pu=Find(sets,u,cu);
			pv=Find(sets,v,cv);
			if(pu==pv)
			{
				if(cu==cv)
					f=1;
				else
					++ans;
			}
			else
			{
				if(cu==cv)
					Union(sets,pu,pv,1);
				else
					Union(sets,pu,pv,0);
				++ans;
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}