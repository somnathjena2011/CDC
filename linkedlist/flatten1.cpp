#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
Node* flatten(Node* root)
{
	if(!root)
		return root;
	if(!(root->left)&&!(root->right))
		return root;
	Node* prev=NULL;
	Node* head=NULL;
	stack<Node*> s;
	Node* curr=root;
	Node* node=NULL;
	Node* next=NULL;
	s.push(root);
	while(!s.empty())
	{
		node=s.top();
		s.pop();
		if(prev)
		{
			prev->left=NULL;
			prev->right=node;
		}
		else
			head=node;
		prev=node;
		if(node->right)
			s.push(node->right);
		if(node->left)
			s.push(node->left);
	}
	return head;
}
void preorder(Node* root)
{
	if(!root)
		return;
	cout<<root->val<<' ';
	preorder(root->left);
	preorder(root->right);
}
int main()
{
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(3);
	root->left->right=new Node(4);
	root->right->right=new Node(6);
	Node* head=flatten(root);
	preorder(head);
	cout<<'\n';
	return 0;
}