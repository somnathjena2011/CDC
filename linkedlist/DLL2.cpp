#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
void convertUtil(Node* root,Node*& head,Node*& tail)
{
	Node* left=root->left;
	Node* right=root->right;
	if(left)
		convertUtil(left,head,tail);
	if(!head)
		head=root;
	root->left=tail;
	if(tail)
		tail->right=root;
	tail=root;
	tail->right=NULL;
	if(right)
		convertUtil(right,head,tail);
}
Node* convert(Node* root)
{
	Node* head=NULL;
	Node* tail=NULL;
	convertUtil(root,head,tail);
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
	root=convert(root);
	while(root)
	{
		cout<<root->val<<' ';
		root=root->right;
	}
	cout<<'\n';
	return 0;
}