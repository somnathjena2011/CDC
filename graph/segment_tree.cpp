#include<bits/stdc++.h>
using namespace std;
class Tree{
public:
	int* a;
	int *tree;
	int n;
	int size;
	Tree(int* a,int n)
	{
		this->a=a;
		this->n=n;
		int x=(int)ceil(log2(n));
		this->size=(1<<(x+1))-1;
		this->tree=new int[size];
	}
	int construct(int arrayStart,int arrayEnd,int treeIndex)
	{
		if(arrayStart==arrayEnd)
		{
			tree[treeIndex]=a[arrayStart];
			return a[arrayStart];
		}
		int mid=arrayStart+(arrayEnd-arrayStart)/2;
		tree[treeIndex]=construct(arrayStart,mid,2*treeIndex+1)
						+construct(mid+1,arrayEnd,2*treeIndex+2);
		return tree[treeIndex];
	}
	int getSumUtil(int queryStart,int queryEnd,int treeStart,int treeEnd,int treeIndex)
	{
		if(treeStart>=queryStart && treeEnd<=queryEnd)
			return tree[treeIndex];
		if(treeEnd<queryStart || treeStart>queryEnd)
			return 0;
		int mid=treeStart+(treeEnd-treeStart)/2;
		return getSumUtil(queryStart,queryEnd,treeStart,mid,2*treeIndex+1)
				+getSumUtil(queryStart,queryEnd,mid+1,treeEnd,2*treeIndex+2);
	}
	int getSum(int queryStart,int queryEnd)
	{
		if(queryStart>queryEnd || queryStart<0 || queryEnd>n-1)
			return INT_MIN;
		return getSumUtil(queryStart,queryEnd,0,n-1,0);
	}
	void updateUtil(int treeStart,int treeEnd,int arrayIndex,int diff,int treeIndex)
	{
		if(arrayIndex<treeStart || arrayIndex>treeEnd)
			return;
		this->tree[treeIndex]=this->tree[treeIndex]+diff;
		if(treeStart!=treeEnd)
		{
			int mid=treeStart+(treeEnd-treeStart)/2;
			updateUtil(treeStart,mid,arrayIndex,diff,2*treeIndex+1);
			updateUtil(mid+1,treeEnd,arrayIndex,diff,2*treeIndex+2);
		}
	}
	void update(int i,int newVal)
	{
		if(i<0||i>=n)
			return;
		int diff=newVal-a[i];
		a[i]=newVal;
		updateUtil(0,n-1,i,diff,0);
	}
};
int main()
{
	int n;
	cin>>n;
	int a[n];
	int i;
	for(i=0;i<n;i++)
		cin>>a[i];
	Tree* sTree = new Tree(a,n);
	sTree->construct(0,n-1,0);
	cout<<sTree->getSum(1,3)<<'\n';
	sTree->update(1,10);
	cout<<sTree->getSum(1,3)<<'\n';
	return 0;
}