#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
void inorder(Node* root,Node*& prev,Node*& head)
{
	if(!root)
		return;
	inorder(root->left,prev,head);
	if(!head)
		head=root;
	if(prev)
	{
		prev->right=root;
		root->left=prev;
	}
	prev=root;
	inorder(root->right,prev,head);
}
Node* convert(Node* root)
{
	Node* head=NULL;
	Node* prev=NULL;
	inorder(root,prev,head);
	return head;
}
int main()
{
	Node* root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(5);
	root->left->left=new Node(3);
	root->left->right=new Node(4);
	root->right->right=new Node(6);
	root=convert(root);
	while(root)
	{
		cout<<root->val<<' ';
		root=root->right;
	}
	cout<<'\n';
	return 0;
}