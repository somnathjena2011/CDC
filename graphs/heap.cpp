#include<bits/stdc++.h>
using namespace std;
int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int parent(int i)
{
	return (i-1)/2;
}
void swap(int* x,int* y)
{
	int t=*x;
	*x=*y;
	*y=t;
}
class Heap{
public:
	int cap;
	int size;
	int* harr;
	Heap(int n)
	{
		int x=(int)ceil(log2(n));
		cap  =(1<<x)-1;
		size =0;
		harr =new int[cap];
	}
	void insert(int k)
	{
		if(size==cap)
			return;
		harr[size]=k;
		int i=size;
		size++;
		while(i!=0&&harr[parent(i)]>=harr[i])
		{
			swap(&harr[parent(i)],&harr[i]);
			i=parent(i);
		}
	}
	int getMin()
	{
		if(size>0)
			return harr[0];
		return INT_MAX;
	}
	void decKey(int i,int nv)
	{
		harr[i]=nv;
		while(i&&harr[parent(i)]>=harr[i])
		{
			swap(&harr[i],&harr[parent(i)]);
			i=parent(i);
		}
	}
	void heapify(int i)
	{
		int sm=i;
		if(left(i)<size&&harr[left(i)]<harr[sm])
			sm=left(i);
		if(right(i)<size&&harr[right(i)]<harr[sm])
			sm=right(i);
		if(sm!=i)
		{
			swap(&harr[i],&harr[sm]);
			heapify(sm);
		}
	}
	int extractMin()
	{
		if(!size)
			return INT_MAX;
		int mini=harr[0];
		harr[0]=harr[size-1];
		size--;
		heapify(0);
		return mini;
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