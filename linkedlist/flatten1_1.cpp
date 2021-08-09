#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
void flatten(Node* root)
{
	if(!root|| (!root->left&&!root->right))
		return;
	if(root->left)
	{
		Node* temp=root->right;
		flatten(root->left);
		root->right=root->left;
		root->left=NULL;
		Node* t=root->right;
		while(t->right)
			t=t->right;
		t->right=temp;
	}
	flatten(root->right);
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
	flatten(root);
	preorder(root);
	cout<<'\n';
	return 0;
}