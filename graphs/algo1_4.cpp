#include<bits/stdc++.h>
using namespace std;
struct Node{
	int vertex;
	Node* next;
	Node(int v):vertex(v),next(NULL){}
};
struct Graph{
	int numVertices;
	Node** adjLists;
	Graph(int n):numVertices(n){
		adjLists = (Node**)malloc((n+1)*sizeof(Node*));
		for(int i=0;i<=n;i++)
			adjLists[i]=NULL;
	}
};
struct Edge{
	int from;
	int to;
	int weight;
	Edge(int f,int t,int w):from(f),to(t),weight(w){}
};
void addEdge(Graph* graph,int from,int to)
{
	Node* node=new Node(to);
	node->next=graph->adjLists[from];
	graph->adjLists[from]=node;
}
void findInDegrees(Graph* graph,int* inDegree)
{
	int n=graph->numVertices;
	int i;Node* node=NULL;
	for(i=1;i<=n;i++)
	{
		node=graph->adjLists[i];
		while(node)
		{
			++inDegree[node->vertex];
			node=node->next;
		}
	}
}
bool compare(Edge e1,Edge e2)
{
	if(e1.from<e2.from)
		return true;
	else if(e1.from==e2.from)
	{
		if(e1.weight<e2.weight)
			return true;
		else if(e1.weight==e2.weight)
		{
			if(e1.to<=e2.to)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
void swap(Edge* e1,Edge* e2)
{
	Edge e3=*e1;
	*e1=*e2;
	*e2=e3;
}
void mergeSort(Edge* edgeGraph,int s,int e)
{
	if(s==e)
		return;
	if(e==s+1)
	{
		if(compare(edgeGraph[s],edgeGraph[e]))
			return;
		else
			swap(&edgeGraph[s],&edgeGraph[e]);
		return;
	}
	int m=s+(e-s)/2;
	mergeSort(edgeGraph,s,m);
	mergeSort(edgeGraph,m+1,e);
	Edge* left=(Edge*)malloc((m-s+1));
	Edge* right=(Edge*)malloc((e-m));
	int i=0,j=0,k=s;
	for(k=s;k<=m;k++)
		left[i++]=edgeGraph[k];
	for( ;k<=e;k++)
		right[j++]=edgeGraph[k];
	i=0;j=0;int l=m-s+1;int r=e-m;k=s;
	while(i<l&&j<r)
	{
		if(compare(left[i],right[j]))
			edgeGraph[k++]=left[i++];
		else
			edgeGraph[k++]=right[j++];
	}
	while(i<l)
		edgeGraph[k++]=left[i++];
	while(j<r)
		edgeGraph[k++]=right[j++];
}
Edge* formEdgeGraph(Graph* graph,int e,int* inDegree)
{
	int i,w;
	Node* node=NULL;
	int n=graph->numVertices;
	Edge* edgeGraph=(Edge*)malloc(e*sizeof(Edge));
	int c=0;
	for(i=1;i<=n;i++)
	{
		node=graph->adjLists[i];
		while(node)
		{
			w=inDegree[i]+inDegree[node->vertex];
			Edge* ed=new Edge(i,node->vertex,w);
			edgeGraph[c]=*ed;
			c++;
			node=node->next;
		}
	}
	return edgeGraph;
}
int main()
{
	FILE* inp = fopen("input.txt","r");
	FILE* out = fopen("output.txt","w");
	int V,E;
	fscanf(inp,"%d",&V);
	fscanf(inp,"%d",&E);
	int i,u,v;
	Graph* graph=new Graph(V);
	for(i=0;i<E;i++)
	{
		fscanf(inp,"%d %d",&u,&v);
		addEdge(graph,u,v);
	}
	int inDegree[V+1]={0};
	findInDegrees(graph,inDegree);
	Edge* edgeGraph=formEdgeGraph(graph,E,inDegree);
	mergeSort(edgeGraph,0,E-1);
	for(i=0;i<E;i++)
		fprintf(out,"%d %d %d\n",edgeGraph[i].from,
			edgeGraph[i].weight,edgeGraph[i].to);
	//fclose(inp);
	//fclose(out);
	free(graph);
	free(edgeGraph);
	return 0;
}