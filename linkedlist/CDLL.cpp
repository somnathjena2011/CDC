#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int val;
	Node* left;
	Node* right;
	Node(int v):val(v),left(NULL),right(NULL){}
};
Node* concat(Node* A,Node* B)
{
	if(!A)
		return B;
	if(!B)
		return A;
	Node* C=A->left;
	Node* D=B->left;
	C->right=B;
	B->left=C;
	A->left=D;
	D->right=A;
	return A;
}
Node* convert(Node* root)
{
	if(!root)
		return NULL;
	Node* left=convert(root->left);
	Node* right=root->right;
	root->left=root->right=root;
	left=concat(left,root);
	right=convert(right);
	concat(left,right);
	return left;
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