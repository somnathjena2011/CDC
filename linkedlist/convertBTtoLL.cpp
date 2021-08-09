#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int val):val(val),left(NULL),right(NULL){}
};
Node* convertBTtoLLUtil(Node* root,Node** tail)
{
	if(root==NULL)
	{
		*tail=NULL;
		return NULL;
	}
	Node* t=NULL;
	Node* leftHead=convertBTtoLLUtil(root->left,&t);
	Node* rightHead=root->right;
	Node* rightT=NULL;
	root->left=NULL;
	root->right=leftHead;
	if(!t)
		t=root;
	rightHead=convertBTtoLLUtil(rightHead,&rightT);
	t->right=rightHead;
	if(rightT)
		*tail=rightT;
	else
		*tail=t;
	return root;
}
Node* convertBTtoLL(Node* root)
{
	if(!root)
		return NULL;
	Node* tail=NULL;
	return convertBTtoLLUtil(root,&tail);
}
void print(Node* root)
{
	while(root)
	{
		if(root->left)
		{
			cout<<"ERROR\n";
			return;
		}
		cout<<root->val<<' ';
		root=root->right;
	}
	cout<<'\n';
}
int main()
{
	Node* root=new Node(10);
	root->left=new Node(12);
	root->right=new Node(15);
	root->left->left=new Node(25);
	root->left->right=new Node(30);
	root->right->right=new Node(36);
	root=convertBTtoLL(root);
	print(root);
	return 0;
}