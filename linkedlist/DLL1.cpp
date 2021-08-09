#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
Node* convertUtil(Node* root)
{
	if(!root||(!root->left&&!root->right))
		return root;
	if(root->left)
	{
		Node* left=convertUtil(root->left);
		while(left->right)
			left=left->right;
		left->right=root;
		root->left=left;
	}
	if(root->right)
	{
		Node* right=convertUtil(root->right);
		while(right->left)
			right=right->left;
		right->left=root;
		root->right=right;
	}
	return root;
}
Node* convert(Node* root)
{
	if(!root)
		return NULL;
	Node* mid=convertUtil(root);
	while(mid->left)
		mid=mid->left;
	return mid;
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