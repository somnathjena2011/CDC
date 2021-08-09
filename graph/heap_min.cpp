#include<bits/stdc++.h>
using namespace std;
class Heap
{
public:
	int capacity;
	int size;
	int* harr;
	Heap(int n)
	{
		this->capacity = n;
		this->size = 0;
		this->harr = new int[n];
	}
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
	void swap(int *x,int* y)
	{
		int t=*x;
		*x=*y;
		*y=t;
	}
	void insert(int k)
	{
		if(size==capacity)
			return;
		size++;
		harr[size-1]=k;
		int i=size-1;
		while(i!=0&&harr[parent(i)]>=harr[i])
		{
			swap(&harr[i],&harr[parent(i)]);
			i=parent(i);
		}
	}
	int getMin()
	{
		if(size>0)
			return harr[0];
		return INT_MAX;
	}
	void decreaseKey(int i,int newVal)
	{
		harr[i]=newVal;
		while(i!=0&&harr[parent(i)]>=harr[i])
		{
			swap(&harr[i],&harr[parent(i)]);
			i=parent(i);
		}
	}
	void heapify(int i)
	{
		int smallest=i;
		if(left(i)<size&&harr[left(i)]<harr[smallest])
			smallest=left(i);
		if(right(i)<size&&harr[right(i)]<harr[smallest])
			smallest=right(i);
		if(smallest!=i)
		{
			swap(&harr[i],&harr[smallest]);
			heapify(smallest);
		}
	}
	int extractMin()
	{
		if(size==0)
			return INT_MAX;
		int mini=harr[0];
		harr[0]=harr[size-1];
		size--;
		heapify(0);
		return mini;
	}
	void deleteKey(int i)
	{
		decreaseKey(i,INT_MIN);
		extractMin();
	}
};
int main()
{
	Heap* h=new Heap(11);
	h->insert(3);
	h->insert(2);
	h->deleteKey(1);
	h->insert(15);
	h->insert(5);
	h->insert(4);
	h->insert(45);
	cout<<h->extractMin()<<'\n';
	cout<<h->getMin()<<'\n';
	h->decreaseKey(2,1);
	cout<<h->getMin()<<'\n';
	return 0;
}