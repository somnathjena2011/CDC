#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node* next;
	Node(int val):val(val),next(NULL){}
};
Node* insert(Node* head,int val)
{
	Node* node=new Node(val);
	node->next=head;
	return node;
}
void print(Node* head)
{
	while(head)
	{
		cout<<head->val<<' ';
		head=head->next;
	}
	cout<<'\n';
}
Node* reverse(Node* head)
{
	Node* curr=head;
	Node* newHead=NULL;
	Node* prev=NULL;
	Node* next=NULL;
	while(curr)
	{
		next=curr->next;
		curr->next=prev;
		newHead=curr;
		prev=curr;
		curr=next;
	}
	return newHead;
}
bool isPalin(Node* head)
{
	if(head==NULL||head->next==NULL)
		return 1;
	if(head->next->next==NULL)
	{
		return head->val==head->next->val;
	}
	Node* ptr1=head;
	Node* ptr2=head;
	while(ptr2->next&&ptr2->next->next)
	{
		ptr1=ptr1->next;
		ptr2=ptr2->next->next;
	}
	Node* head1=head;
	Node* head2=reverse(ptr1->next);
	while(head1&&head2)
	{
		if(head1->val!=head2->val)
			return 0;
		head1=head1->next;
		head2=head2->next;
	}
	return 1;
}
int main()
{
	Node* head=NULL;
	int n,i,v;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>v;
		head=insert(head,v);
	}
	print(head);
	cout<<isPalin(head)<<'\n';
	return 0;
}