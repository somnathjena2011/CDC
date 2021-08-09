#include<bits/stdc++.h>
using namespace std;
class Tree{
public:
	int *a;
	int *st;
	int n;
	int size;
	Tree(int* a,int n)
	{
		this->a=a;
		this->n=n;
		int x=(int)ceil(log2(n));
		this->size=(1<<(x+1))-1;
		this->st=new int[size];
	}
	int construct(int s,int e,int i)
	{
		if(s>e)
			return INT_MIN;
		if(s==e)
		{
			st[i]=a[s];
			return st[i];
		}
		int m=s+(e-s)/2;
		st[i]=construct(s,m,2*i+1)^construct(m+1,e,2*i+2);
		return st[i];
	}
	int getXorUtil(int queryStart,int queryEnd,int treeStart,int treeEnd,int treeIndex)
	{
		if(treeStart>=queryStart&&treeEnd<=queryEnd)
			return st[treeIndex];
		if(treeStart>queryEnd||treeEnd<queryStart)
			return 0;
		int mid=treeStart+(treeEnd-treeStart)/2;
		return getXorUtil(queryStart,queryEnd,treeStart,mid,2*treeIndex+1)
				^getXorUtil(queryStart,queryEnd,mid+1,treeEnd,2*treeIndex+2);
	}
	int getXor(int queryStart,int queryEnd)
	{
		if(queryStart<0 || queryEnd>=n || queryStart>queryEnd)
			return 0;
		return getXorUtil(queryStart,queryEnd,0,n-1,0);
	}
	void updateUtil(int treeStart,int treeEnd,int i,int treeIndex,int val)
	{
		if(i<treeStart || i>treeEnd)
			return;
		st[treeIndex]=st[treeIndex]^val;
		if(treeStart!=treeEnd)
		{
			int mid=treeStart+(treeEnd-treeStart)/2;
			updateUtil(treeStart,mid,i,2*treeIndex+1,val);
			updateUtil(mid+1,treeEnd,i,2*treeIndex+2,val);
		}
	}
	void update(int i,int newVal)
	{
		if(i<0||i>=n)
			return;
		int diff=a[i]^newVal;
		a[i]=newVal;
		updateUtil(0,n-1,i,0,diff);
	}
};
int main()
{
	int a[6]={3,5,7,9,11,12};
	Tree* tree=new Tree(a,6);
	tree->construct(0,5,0);
	cout<<tree->getXor(1,3)<<'\n';
	cout<<tree->getXor(2,5)<<'\n';
	tree->update(1,10);
	cout<<tree->getXor(1,3)<<'\n';
	return 0;
}