#include<bits/stdc++.h>
using namespace std;
/*
O(EV)
run for V-1 times
each time relax an edge and see if it reduces distance to v
if yes then update
run the algo 1 more time, if any single relaxation possible,
it means negative weight cycle is present
->works on -ve edge weights
->doesn't work if there is a -ve edge cycle
->doesn't work with undirected graph with -ve edges as it will
declare them as -ve weight cycles

BELLMAN FORD CAN BE MODIFIED TO FIND SHORTEST DISTANCE
IN -ve WEIGHT CYCLES GRAPHS

When we run BF for Vth time, if we see that dist[v] gets reduced
because of  edge u->v, it means u->v is on a negative weight cycle
We can run dfs once from u,and once from v to mark dist to
all the vertices reachable from u and v as INT_MIN
OR
We can find all the nodes on the negative cycle by storing
parents when we update dist[v], we traverse back to parents
till we reach same node again
Now we create a dummy node s and make directed edges from s 
to all nodes on negative weight cycle
Running dfs from s, we mark all reachable nodes' dist as INT_MIN
*/
bool bellman(vector<vector<int>>& edges,int dist[],int n,int s)
{
	int i;
	for(i=0;i<n;i++)
		dist[i]=INT_MAX;
	dist[0]=0;
	int u,v,w;
	for(i=1;i<n;i++)
	{
		for(auto ed:edges)
		{
			u=ed[0];v=ed[1];w=ed[2];
			if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
				dist[v]=dist[u]+w;
		}
	}
	for(auto ed:edges)
	{
		u=ed[0];v=ed[1];w=ed[2];
		if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
			return false;
	}
	return true;
}
int main()
{
	int n,e,i,u,v,w;
	cin>>n>>e;
	int dist[n];
	vector<vector<int>> edges(e);
	vector<int> ed(3);
	for(i=0;i<e;i++)
	{
		cin>>u>>v>>w;
		ed[0]=u;ed[1]=v;ed[2]=w;
		edges[i]=ed;
	}
	int s;
	cin>>s;
	bool cycle=bellman(edges,dist,n,s);
	if(!cycle)
		cout<<"Negative weight cycle\n";
	else
	{
		for(i=0;i<n;i++)
			cout<<dist[i]<<' ';
		cout<<'\n';
	}
	return 0;
}