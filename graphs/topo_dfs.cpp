// #include<bits/stdc++.h>
// using namespace std;
// bool topo(vector<int> adj[],int s,int colors[],stack<int>& st)
// {
// 	colors[s]=1;
// 	for(int v:adj[s])
// 	{
// 		if(!colors[v])
// 		{
// 			if(!topo(adj,v,colors,st))
// 				return false;
// 		}
// 		else if(colors[v]==1)
// 		{
// 			//cycle in graph
// 			return false;
// 		}
// 	}
// 	colors[s]=2;
// 	st.push(s);
// 	return true;
// }
// int main()
// {
// 	int n,e,i,u,v;
// 	cin>>n>>e;
// 	vector<int> adj[n];
// 	for(i=0;i<e;i++)
// 	{
// 		cin>>u>>v;
// 		adj[u].push_back(v);
// 	}
// 	int colors[n]={0};
// 	stack<int> s;bool f=1;
// 	for(i=0;i<n;i++)
// 	{
// 		if(!colors[i])
// 		{
// 			f=topo(adj,i,colors,s);
// 		}
// 		if(!f)
// 			break;
// 	}
// 	if(!f)
// 		cout<<"Not possible\n";
// 	else
// 	{
// 		while(!s.empty())
// 		{
// 			cout<<s.top()<<' ';
// 			s.pop();
// 		}
// 		cout<<'\n';
// 	}
// 	return 0;
// }
#include<bits/stdc++.h>
using namespace std;
bool sort(vector<int> adj[],vector<int>& color,stack<int>& st,int s)
{
	color[s]=1;
	for(int v:adj[s])
	{
		if(color[v]==1)
			return false;
		else if(!color[v])
			sort(adj,color,st,v);
	}
	color[s]=2;
	st.push(s);
	return true;
}
int main()
{
	int n,e,u,v,i;
	cin>>n>>e;
	vector<int> adj[n];
	while(e--)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	vector<int> color(n,0);
	stack<int> st;
	for(i=0;i<n;i++)
	{
		if(!color[i]&&!sort(adj,color,st,i))
		{
			cout<<"Cycle\n";
			return 0;
		}
	}
	while(!st.empty())
	{
		cout<<st.top()<<' ';
		st.pop();
	}
	cout<<'\n';
	return 0;
}