#include<bits/stdc++.h>
using namespace std;
struct Node
{
	Node* next;
	int val;
	Node(int val):next(NULL),val(val){}
};
int length(Node* A)
{
	int l=0;
	while(A)
	{
		++l;
		A=A->next;
	}
	return l;
}
Node* addEqual(Node* A,Node* B,int &c)
{
	if(!A&&!B)
		return NULL;
	if(A->next==NULL&&B->next==NULL)
	{
		int s=A->val+B->val;
		int d=s%10;
		c=s/10;
		Node* node=new Node(d);
		return node;
	}
	Node* next=addEqual(A->next,B->next,c);
	int s=A->val+B->val+c;
	int d=s%10;
	c=s/10;
	Node* node=new Node(d);
	node->next=next;
	return node;
}
Node* addSingle(Node* A,int d,int& c,int D)
{
	int s;
	if(d==D)
	{
		if(A)
			s=A->val+c;
		else
			s=c;
		int d=s%10;
		c=s/10;
		Node* node=new Node(d);
		return node;
	}
	if(D==0&&c>0)
	{
		Node* node=new Node(c);
		c=0;
		return node;
	}
	if(D==0&&c==0)
		return NULL;
	Node* next=addSingle(A->next,d+1,c,D);
	s=A->val+c;
	int di=s%10;
	c=s/10;
	Node* node=new Node(di);
	node->next=next;
	return node;
}
Node* add(Node* A,Node* B)
{
	if(!A)return B;
	if(!B)return A;
	int n=length(A);
	int m=length(B);
	Node* c1=NULL;Node* c2=NULL;
	if(n>m)
	{
		c1=A;c2=B;
	}
	else
	{
		c1=B;c2=A;
	}
	int d=abs(n-m);
	int i;
	Node* c3=c1;
	for(i=1;i<=d;i++)
		c3=c3->next;
	int c=0;
	Node* equal=addEqual(c2,c3,c);
	//cout<<"c="<<c<<'\n';
	Node* single=addSingle(c1,1,c,d);
	if(c>0)
	{
		Node* node=new Node(c);
		node->next=single;
		single=node;
	}
	Node* ans=single;
	if(!single)
		return equal;
	while(single->next)
		single=single->next;
	single->next=equal;
	return ans;
}
int main()
{
	int n,m;
	Node* A=NULL;Node* B=NULL;
	Node* prev=NULL;
	cin>>n>>m;
	int i,d;
	for(i=0;i<n;i++)
	{
		cin>>d;
		Node* node=new Node(d);
		if(prev)
			prev->next=node;
		else
			A=node;
		prev=node;
	}
	prev=NULL;
	for(i=0;i<m;i++)
	{
		cin>>d;
		Node* node=new Node(d);
		if(prev)
			prev->next=node;
		else
			B=node;
		prev=node;
	}
	Node* ans=add(A,B);
	while(ans)
	{
		cout<<ans->val;
		ans=ans->next;
	}
	cout<<'\n';
	return 0;
}