#include<bits/stdc++.h>
using namespace std;
int parent(int i)
{
	return (i-1)/2;
}
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
struct Heap
{
	int cap;
	int size;
	int* harr;
	Heap(int n)
	{
		int x=(int)ceil(log2(n));
		cap=(1<<(x+1))-1;
		harr=new int[cap];
		size=0;
	}
	void insert(int key)
	{
		if(size==cap)
			return;
		harr[size]=key;
		int i=size;
		size++;
		while(i&&harr[parent(i)]>=harr[i])
		{
			swap(harr[parent(i)],harr[i]);
			i=parent(i);
		}
	}
	int getMin()
	{
		if(size==0)
			return INT_MAX;
		return harr[0];
	}
	void heapify(int i)
	{
		int l=left(i);
		int r=right(i);
		int s=i;
		if(l<size&&harr[l]<harr[s])
			s=l;
		if(r<size&&harr[r]<harr[s])
			s=r;
		if(s!=i)
		{
			swap(harr[s],harr[i]);
			heapify(s);
		}
	}
	int extractMin()
	{
		if(size==0)
			return INT_MAX;
		int ans=harr[0];
		swap(harr[0],harr[size-1]);
		size--;
		heapify(0);
		return ans;
	}
	void decKey(int i,int nv)
	{
		if(i>=size||harr[i]<nv)
			return;
		harr[i]=nv;
		while(i&&harr[parent(i)]>=harr[i])
		{
			swap(harr[i],harr[parent(i)]);
			i=parent(i);
		}
	}
	void del(int i)
	{
		decKey(i,INT_MIN);
		extractMin();
	}
};
int main()
{
	Heap* h=new Heap(11);
	h->insert(3);
	h->insert(2);
	h->del(1);
	h->insert(15);
	h->insert(5);
	h->insert(4);
	h->insert(45);
	cout<<h->extractMin()<<'\n';
	cout<<h->getMin()<<'\n';
	h->decKey(2,1);
	while(h->size)
		cout<<h->extractMin()<<'\n';
	return 0;
}