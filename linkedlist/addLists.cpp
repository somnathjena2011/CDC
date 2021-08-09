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
Node* add(Node* l1,Node* l2)
{
	stack<int> s1,s2;
	while(l1)
	{
		s1.push(l1->val);
		l1=l1->next;
	}
	while(l2)
	{
		s2.push(l2->val);
		l2=l2->next;
	}
	Node* ans=NULL;
	int sum,d1,d2,d,carry=0;
	while(!s1.empty()||!s2.empty()||carry)
	{
		d1=d2=0;
		if(!s1.empty())
		{
			d1=s1.top();
			s1.pop();
		}
		if(!s2.empty())
		{
			d2=s2.top();
			s2.pop();
		}
		sum=d1+d2+carry;
		d=sum%10;
		carry=sum/10;
		ans=insert(ans,d);
	}
	return ans;
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