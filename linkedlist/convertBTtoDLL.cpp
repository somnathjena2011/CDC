#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int val):val(val),left(NULL),right(NULL){}
};
Node* convertBTtoDLLUtil(Node* root)
{
	if(root==NULL)
		return root;
	if(root->left)
	{
		Node* left=convertBTtoDLLUtil(root->left);
		while(left->right!=NULL)
			left=left->right;
		left->right=root;
		root->left=left;
	}
	if(root->right)
	{
		Node* right=convertBTtoDLLUtil(root->right);
		while(right->left!=NULL)
			right=right->left;
		right->left=root;
		root->right=right;
	}
	return root;
}
void convertBTtoDLLUtil(Node* root,Node** head,Node** tail)
{
	if(root==NULL)
		return;
	Node* left=root->left;
	Node* right=root->right;
	convertBTtoDLLUtil(left,head,tail);
	if(!(*head))
		*head=root;
	root->left=*tail;
	if(*tail)
		(*tail)->right=root;
	*tail=root;
	convertBTtoDLLUtil(right,head,tail);
}
Node* convertBTtoDLL(Node* root)
{
	if(root==NULL)
		return NULL;
	root=convertBTtoDLLUtil(root);
	while(root->left!=NULL)
		root=root->left;
	return root;
}
Node* convertBTtoDLL2(Node* root)
{
	if(root==NULL)
		return NULL;
	Node* head=NULL;
	Node* tail=NULL;
	convertBTtoDLLUtil(root,&head,&tail);
	return head;
}
void convertBTtoDLL3(Node* root,Node** head)
{
	if(root==NULL)
		return;
	static Node* prev=NULL;
	convertBTtoDLL3(root->left,head);
	if(prev==NULL)
		*head=root;
	else
		prev->right=root;
	root->left=prev;
	prev=root;
	convertBTtoDLL3(root->right,head);
}
Node* convertBTtoDLL4(Node* root)
{
	if(root==NULL)
		return NULL;
	static Node* prev=NULL;
	Node* head=convertBTtoDLL4(root->left);
	if(prev==NULL)
		head=root;
	else
		prev->right=root;
	root->left=prev;
	prev=root;
	convertBTtoDLL4(root->right);
	return head;
}
void print(Node* root)
{
	while(root)
	{
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
	//Node* head=convertBTtoDLL(root);
	//Node* head=convertBTtoDLL2(root);
	//Node* head=NULL;
	//convertBTtoDLL3(root,&head);
	Node* head=convertBTtoDLL4(root);
	print(head);
	return 0;
}