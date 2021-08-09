#include<bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	unsigned long int xr;
	Node(int key):key(key),xr(0){}
};
Node* create(int key)
{
	Node* node=new Node(key);
	return node;
}
void insert(Node** headPtr,Node** tailPtr,int key)
{
	Node* head=*headPtr;
	Node* tail=*tailPtr;
	if(head==NULL)
	{
		head=tail=create(key);
		*headPtr=*tailPtr=head;
	}
	else
	{
		Node* node=create(key);
		node->xr  =(unsigned long int)head;
		head->xr  =head->xr ^ (unsigned long int)node;
		head      =node;
		*headPtr  =head;
	}
}
void traverse_from_front_to_end(Node* head)
{
	unsigned long int prev=0;
	Node* temp=NULL;
	unsigned long int next=(unsigned long int)head;
	while(next)
	{
		temp=(Node*)next;
		cout<<temp->key<<' ';
		next=prev^(temp->xr);
		prev=(unsigned long int)temp;
	}
	cout<<'\n';
}
void traverse_from_end_to_front(Node* tail)
{
	unsigned long int prev=0;
	Node* temp=NULL;
	unsigned long int next=(unsigned long int)tail;
	while(next)
	{
		temp=(Node*)next;
		cout<<temp->key<<' ';
		next=prev^(temp->xr);
		prev=(unsigned long int)temp;
	}
	cout<<'\n';
}
void reverse(Node** head,Node** tail)
{
	Node* h=*head;
	Node* t=*tail;
	*head=t;
	*tail=h;
}
void sort(Node** head,Node** tail)
{
	Node* h=*head;
	Node* t=*tail;
	if(h==NULL)
		return;
	unsigned long int prev=0;
	unsigned long int next=(unsigned long int)h;
	int k1,k2;
	unsigned long int n0,n1,n2,n3,x1,x2,x;
	Node* t0=NULL;
	Node* t1=NULL;
	Node* t2=NULL;
	Node* t3=NULL;
	int f=0;
	while(1)
	{
		prev=0;f=0;next=(unsigned long int)h;
		while(next)
		{
			n1=next;
			t1=(Node*)next;
			x1=t1->xr;
			n2=prev^x1;
			if(n2==0)
				break;
			t2=(Node*)n2;
			x2=t2->xr;
			if(t1->key <= t2->key)
			{
				prev=n1;
				next=n2;
			}
			else
			{
				f=1;
				n0=prev;
				n3=x2^n1;
				x=(x1^x2)^(n1^n2);
				t0=(Node*)n0;
				t3=(Node*)n3;
				if(t0)
					t0->xr=(t0->xr)^(n1^n2);
				if(t3)
					t3->xr=(t3->xr)^(n1^n2);
				if(h==t1)
					h=t2;
				if(t==t2)
					t=t1;
				t1->xr=x1^x;
				t2->xr=x2^x;
				prev=n2;
				next=n1;
			}
		}
		if(!f)
			break;
	}
	*head=h;
	*tail=t;
}
Node* createList()
{
	Node* node=new Node(rand()%200000);
	return node;
}
int main()
{
	Node* head=NULL;
	Node* tail=NULL;
	int n,i;
	cin>>n;
	head=tail=createList();
	for(i=0;i<n-1;i++)
		insert(&head,&tail,rand()%200000);
	traverse_from_front_to_end(head);
	traverse_from_end_to_front(tail);
	reverse(&head,&tail);
	traverse_from_front_to_end(head);
	traverse_from_end_to_front(tail);
	sort(&head,&tail);
	traverse_from_front_to_end(head);
	traverse_from_end_to_front(tail);
	return 0;
}