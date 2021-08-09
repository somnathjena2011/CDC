// #include<bits/stdc++.h>
// using namespace std;
// bool cycle(vector<int> adj[],int s,int* colors)
// {
// 	colors[s]=1;
// 	cout<<s<<' ';
// 	for(int v:adj[s])
// 	{
// 		if(colors[v]==1)
// 			return true;
// 		if(!colors[v])
// 		{
// 			if(cycle(adj,v,colors))
// 				return true;
// 		}
// 	}
// 	colors[s]=2;
// 	return false;
// }
// int main()
// {
// 	int n,e;
// 	cin>>n>>e;
// 	vector<int> adj[n];
// 	int i,u,v;
// 	for(i=0;i<e;i++)
// 	{
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 	}
// 	int colors[n]={0};
// 	//0=white, 1=gray, 2=black
// 	for(i=0;i<n;i++)
// 	{
// 		if(!colors[i])
// 		{
// 			if(cycle(adj,i,colors))
// 			{
// 				cout<<'\n';
// 				cout<<"Found\n";
// 				return 0;
// 			}
// 			cout<<'\n';
// 		}
// 	}
// 	cout<<"Not Found\n";
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
bool cycle(vector<int> adj[],vector<int>& color,int s)
{
	color[s]=1;
	cout<<s<<' ';
	for(int v:adj[s])
	{
		if(color[v]==1)
			return true;
		if(!color[v]&&cycle(adj,color,v))
			return true;
	}
	color[s]=2;
	return false;
}
int main()
{
	int n,e,u,v;
	cin>>n>>e;
	vector<int> adj[n];
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<int> color(n,0);
	for(int i=0;i<n;i++)
	{
		if(!color[i]&&cycle(adj,color,i))
		{
			cout<<"Found\n";
			return 0;
		}
	}
	cout<<"Not Found\n";
	return 0;
}