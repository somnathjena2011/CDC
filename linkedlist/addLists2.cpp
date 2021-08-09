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
int length(Node* head)
{
	int l=0;
	while(head)
	{
		++l;
		head=head->next;
	}
	return l;
}
Node* addOne(Node* l1,Node* com,Node* res,int& carry)
{
	int sum;
	if(l1!=com)
	{
		res=addOne(l1->next,com,res,carry);
		sum=carry+l1->val;
		carry=sum/10;
		sum%=10;
		Node* node=new Node(sum);
		node->next=res;
		return node;
	}
	return res;
}
Node* addSame(Node* l1,Node* l2,int& carry)
{
	if(!l1)
		return NULL;
	Node* next=NULL;
	int sum=0;
	if(l1->next)
		next=addSame(l1->next,l2->next,carry);
	sum=l1->val+l2->val+carry;
	Node* node=new Node(sum%10);
	carry=sum/10;
	node->next=next;
	return node;
}
Node* add(Node* l1,Node* l2)
{
	if(l1==NULL)
		return l2;
	if(l2==NULL)
		return l1;
	int n=length(l1);
	int m=length(l2);
	if(n<m)
	{
		Node* t=l1;
		l1=l2;
		l2=t;
	}
	int d=abs(n-m);
	int i=0;
	Node* com=l1;
	while(i<d)
	{
		com=com->next;
		i++;
	}
	int carry=0;
	Node* res=addSame(com,l2,carry);
	res=addOne(l1,com,res,carry);
	if(carry>0)
	{
		Node* node=new Node(carry);
		node->next=res;
		res=node;
	}
	return res;
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
	int m,n,i,x;
	cin>>m>>n;
	Node* l1=NULL;
	Node* l2=NULL;
	i=0;
	while(i<m)
	{
		cin>>x;
		l1=insert(l1,x);
		i++;
	}
	i=0;
	while(i<n)
	{
		cin>>x;
		l2=insert(l2,x);
		i++;
	}
	print(l1);
	print(l2);
	Node* ans=add(l1,l2);
	print(ans);
	return 0;
}