#include<bits/stdc++.h>
using namespace std;
struct Node {
	int val;
	Node* next;
	Node(int val):val(val),next(NULL){}
};
Node* insert(Node* head,int val)
{
	Node* node=new Node(val);
	if(head==NULL)
		return node;
	else
	{
		node->next=head;
		return node;
	}
}
Node* merge(Node* head1,Node* head2)
{
	if(head1==NULL)
		return head2;
	if(head2==NULL)
		return head1;
	Node* curr1=head1;
	Node* curr2=head2;
	Node* curr=NULL;
	Node* head=NULL;
	while(curr1&&curr2)
	{
		if(curr1->val <= curr2->val)
		{
			if(curr)
			{
				curr->next=curr1;
				curr=curr->next;
			}
			else
				curr=head=curr1;
			curr1=curr1->next;
		}
		else
		{
			if(curr)
			{
				curr->next=curr2;
				curr=curr->next;
			}
			else
				curr=head=curr2;
			curr2=curr2->next;
		}
	}
	while(curr1)
	{
		curr->next=curr1;
		curr=curr->next;
		curr1=curr1->next;
	}
	while(curr2)
	{
		curr->next=curr2;
		curr=curr->next;
		curr2=curr2->next;
	}
	return head;
}
Node* sort(Node* head)
{
	if(head==NULL||head->next==NULL)
		return head;
	if(head->next->next==NULL)
	{
		if(head->val <= head->next->val)
			return head;
		else
		{
			Node* temp=head->next;
			temp->next=head;
			head->next=NULL;
			return temp;
		}
	}
	Node* ptr1=head;
	Node* ptr2=head;
	Node* head1=head;
	Node* head2=NULL;
	while(ptr1&&ptr2)
	{
		if(ptr2->next==NULL||ptr2->next->next==NULL)
		{
			ptr2=ptr1->next;
			ptr1->next=NULL;
			break;
		}
		else
		{
			ptr1=ptr1->next;
			ptr2=ptr2->next->next;
		}
	}
	head1=sort(head);
	head2=sort(ptr2);
	return merge(head1,head2);
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
int main()
{
	int n,val;
	cin>>n;
	Node* head=NULL;
	for(int i=0;i<n;i++)
	{
		cin>>val;
		head=insert(head,val);
	}
	print(head);
	head=sort(head);
	print(head);
	return 0;
}