#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	Node* left;
	Node* right;
	Node(int val):val(val),left(NULL),right(NULL){}
};
Node* concat(Node* leftList,Node* rightList)
{
	if(leftList==NULL)
		return rightList;
	if(rightList==NULL)
		return leftList;
	Node* leftLast=leftList->left;
	Node* rightLast=rightList->left;
	leftLast->right=rightList;
	rightList->left=leftLast;
	leftList->left=rightLast;
	rightLast->right=leftList;
	return leftList;
}
Node* convertBTtoCDLL(Node* root)
{
	if(root==NULL)
		return NULL;
	Node* leftList=convertBTtoCDLL(root->left);
	Node* rightList=convertBTtoCDLL(root->right);
	root->left=root->right=root;
	leftList=concat(leftList,root);
	leftList=concat(leftList,rightList);
	return leftList;
}
void print(Node* root)
{
	if(!root)
	{
		cout<<'\n';
		return;
	}
	Node* head=root;
	cout<<head->val<<' ';
	root=root->right;
	while(root&&root!=head)
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
	Node* head=convertBTtoCDLL(root);
	print(head);
	return 0;
}