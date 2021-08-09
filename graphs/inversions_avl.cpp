#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	int height;
	int size;
	Node(int val)
	{
		this->val=val;
		size=height=1;
		left=right=NULL;
	}
};
int height(Node* root)
{
	if(!root)
		return 0;
	return root->height;
}
int size(Node* root)
{
	if(!root)
		return 0;
	return root->size;
}
int balance(Node* root)
{
	int l=height(root->left);
	int r=height(root->right);
	return l-r;
}
Node* rightRotate(Node* root)
{
	Node* z=root;
	Node* y=root->left;
	Node* x=y->right;

	z->left=x;
	z->size=size(x)+size(z->right)+1;
	z->height=max(height(x),height(z->right))+1;

	y->right=z;
	y->size=size(y->left)+size(z)+1;
	y->height=max(height(y->left),height(z))+1;

	return y;
}
Node* leftRotate(Node* root)
{
	Node* z=root;
	Node* y=root->right;
	Node* x=y->left;

	z->right=x;
	z->size=size(x)+size(z->left)+1;
	z->height=max(height(x),height(z->left))+1;

	y->left=z;
	y->size=size(y->right)+size(z)+1;
	y->height=max(height(y->right),height(z))+1;

	return y;
}
Node* insert(Node* node,int val,int& count)
{
	if(node==NULL)
		return new Node(val);
	if(val<node->val)
	{
		count+=size(node->right)+1;
		node->left=insert(node->left,val,count);
	}
	else
		node->right=insert(node->right,val,count);
	node->height=max(height(node->left),height(node->right))+1;
	node->size=size(node->left)+size(node->right)+1;

	int bal=balance(node);
	if(bal<=1&&bal>=-1)
		return node;
	if(bal>1&&val<node->left->val)
		return rightRotate(node);
	if(bal<-1&&val>=node->right->val)
		return leftRotate(node);
	if(bal>1)
	{
		node->left=leftRotate(node->left);
		return rightRotate(node);
	}
	if(bal<-1)
	{
		node->right=rightRotate(node->right);
		return leftRotate(node);
	}
}
void inorder(Node* node)
{
	if(!node)
		return;
	inorder(node->left);
	cout<<node->val<<' ';
	inorder(node->right);
}
int main()
{
	vector<int> a={6,5,7,4,3};
	Node* root=NULL;
	int ans=0;
	for(int el:a)
		root=insert(root,el,ans);
	cout<<ans<<'\n';
	return 0;
}