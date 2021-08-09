#include<bits/stdc++.h>
using namespace std;
struct Node{
	int key;
	unsigned long int xr;
	//constructor to initialize key with key
	//and xr with xor of NULL(left) & NULL(right)=0
	Node(int key):key(key),xr(0){}
};
/*
create a new Node
*/
Node* create(int key)
{
	Node* node=new Node(key);
	return node;
}
/*
Create a new list with only one node
*/
Node* createList()
{
	Node* node=create(rand()%200000);
	return node;
}
/*
insert a new node at beginning
head is expected to be not null
*/
void insert(Node** head,int key)
{
	Node* h   =*head;
	Node* node=create(key);
	//node->xr=0^address of previous head
	node->xr  =(unsigned long int)h;
	//previous head->xr=next^new, since prev was 0
	//so prev h->xr was next
	h->xr     =(h->xr)^(unsigned long int)node;
	h         =node;
	*head     =h;
}
/*
traverse list from front to end
*/
void traverse_from_front_to_end(Node* head)
{
	unsigned long int prev=0;
	unsigned long int next=(unsigned long int)head;
	Node* temp=NULL;
	while(next)
	{
		//obtain next node to print
		temp=(Node*)next;
		cout<<temp->key<<' ';
		//update next node using xor of prev node & this xor
		next=prev^(temp->xr);
		//update previous node to this node
		prev=(unsigned long int)temp;
	}
	cout<<'\n';
}
/*
traverse list from end to front
similar to front to end, except we begin from tail
*/
void traverse_from_end_to_front(Node* tail)
{
	unsigned long int prev=0;
	unsigned long int next=(unsigned long int)tail;
	Node* temp=NULL;
	while(next)
	{
		//obtain next node to print
		temp=(Node*)next;
		cout<<temp->key<<' ';
		//update next node using xor of prev node & this xor
		next=prev^(temp->xr);
		//update previous node to this node
		prev=(unsigned long int)temp;
	}
	cout<<'\n';
}
/*
reverse list
*/
void reverse(Node** head,Node** tail)
{
	//simply swap head and tail pointers
	Node* h=*head;
	Node* t=*tail;
	*head=t;
	*tail=h;
}
/*
perform bubble sort
*/
void sort(Node** head,Node** tail)
{
	Node* h=*head;
	Node* t=*tail;
	Node* t0=NULL;
	Node* t1=NULL;
	Node* t2=NULL;
	Node* t3=NULL;
	unsigned long int n0,n1,n2,n3;
	int f=0;//f=1 indicates a swap is performed in a pass
	unsigned long int prev,next;
	while(1)
	{
		prev=0;next=(unsigned long int)h;f=0;
		while(next)
		{
			n0=prev;
			n1=next;
			t0=(Node*)n0;
			t1=(Node*)n1;
			n2=n0^(t1->xr);
			t2=(Node*)n2;
			//if no next node break out of loop
			if(!n2)
				break;
			if(t1->key <= t2->key)
			{
				//no swap needed
				prev=n1;//prev is current node then
				next=n2;//next will be the next node
				continue;
			}
			f=1;//swap will be performed
			n3=n1^(t2->xr);
			t3=(Node*)n3;
			//n0->n1->n2->n3 (I need to swap n1 & n2)
			t1->xr=n2^n3;
			t2->xr=n0^n1;
			if(t0)
				t0->xr=(t0->xr)^(n1^n2);
			if(t3)
				t3->xr=(t3->xr)^(n1^n2);
			//update head and tail pointers if needed
			if(t1==h)
				h=t2;
			if(t2==t)
				t=t1;
			next=n1;
			prev=n2;
		}
		if(!f)//sorted
			break;
	}
	*head=h;
	*tail=t;
}
int main()
{
	Node* head=NULL;
	Node* tail=NULL;
	int n;
	cin>>n;//no of nodes
	if(n<=0)
		return 0;
	head=createList();
	tail=head;
	for(int i=0;i<n-1;i++)
		insert(&head,rand()%200000);
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