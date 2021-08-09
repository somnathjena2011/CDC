#include<bits/stdc++.h>
using namespace std;
class Tree{
public:
	int* a;
	int* t;
	int n;
	int size;
	Tree(int* a,int n)
	{
		this->a=a;
		this->n=n;
		int x=(int)ceil(log2(n));
		this->size=(1<<(x+1))-1;
		this->t=new int[size];
	}
	int construct(int as,int ae,int ti)
	{
		if(as==ae)
			return t[ti]=a[as];
		int m=as+(ae-as)/2;
		t[ti]=construct(as,m,2*ti+1)+construct(m+1,ae,2*ti+2);
		return t[ti];
	}
	int getSumUtil(int qs,int qe,int as,int ae,int ti)
	{
		if(as>=qs&&ae<=qe)
			return t[ti];
		if(as>qe||ae<qs)
			return 0;
		int m=as+(ae-as)/2;
		return getSumUtil(qs,qe,as,m,2*ti+1)+getSumUtil(qs,qe,m+1,ae,2*ti+2);
	}
	int getSum(int qs,int qe)
	{
		if(qs>qe || qs<0 || qe>=n)
			return INT_MIN;
		return getSumUtil(qs,qe,0,n-1,0);
	}
	void updateUtil(int as,int ae,int ai,int d,int ti)
	{
		if(ai<as||ai>ae)
			return;
		t[ti]+=d;
		if(as!=ae)
		{
			int m=as+(ae-as)/2;
			updateUtil(as,m,ai,d,2*ti+1);
			updateUtil(m+1,ae,ai,d,2*ti+2);
		}
	}
	void update(int i,int nv)
	{
		if(i<0||i>=n)return;
		int d=nv-a[i];
		a[i]=nv;
		updateUtil(0,n-1,i,d,0);
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
	Tree* tree=new Tree(a,n);
	tree->construct(0,n-1,0);
	cout<<tree->getSum(1,3)<<'\n';
	tree->update(1,10);
	cout<<tree->getSum(1,3)<<'\n';
	return 0;
}