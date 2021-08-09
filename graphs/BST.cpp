#include<bits/stdc++.h>
using namespace std;
struct Node{
	int key;
	Node* left;
	Node* right;
	Node(int key):key(key),left(NULL),right(NULL){}
};
class Tree{
public:
	Node* root;
	Tree()
	{
		this->root=NULL;
	}
	bool empty()
	{
		return root==NULL;
	}
	Node* search(int key)
	{
		Node* curr=this->root;
		while(curr!=NULL)
		{
			if(curr->key==key)
				return curr;
			else if(curr->key < key)
				curr=curr->right;
			else
				curr=curr->left;
		}
		return NULL;
	}
	void insert(int key)
	{
		Node* i=new Node(key);
		if(root==NULL)
		{
			root=i;
			return;
		}
		Node* p=NULL;
		Node* c=root;
		while(c!=NULL)
		{
			p=c;
			if(key < c->key)
				c=c->left;
			else
				c=c->right;
		}
		if(key < p->key)
			p->left=i;
		else
			p->right=i;
	}
	Node* maximum(Node* x)
	{
		while(x&&x->right)
			x=x->right;
		return x;
	}
	Node* minimum(Node* x)
	{
		while(x&&x->left)
			x=x->left;
		return x;
	}
	Node* successor(int val)
	{
		Node* x=search(val);
		if(x==NULL)
			return NULL;
		if(x->right)
			return minimum(x->right);
		Node* p=NULL;
		Node* c=root;
		while(c&&c!=x)
		{
			if(val < c->key)
			{
				p=c;
				c=c->left;
			}
			else
				c=c->right;
		}
		return p;
	}
	Node* predecessor(int val)
	{
		Node* x=search(val);
		if(x==NULL)
			return NULL;
		if(x->left)
			return maximum(x->left);
		Node* p=NULL;
		Node* c=root;
		while(c&&c!=x)
		{
			if(val > c->key)
			{
				p=c;
				c=c->right;
			}
			else
				c=c->left;
		}
		return p;
	}
	Node* del(Node* x,int val)
	{
		if(x==NULL)
			return x;
		else if(val < x->key)
			x->left=del(x->left,val);
		else if(val > x->key)
			x->right=del(x->right,val);
		else
		{
			if(x->left==NULL&&x->right==NULL)
			{
				delete(x);
				x=NULL;
			}
			else if(x->left==NULL)
			{
				Node* temp=x;
				x=x->right;
				delete(temp);
			}
			else if(x->right==NULL)
			{
				Node* temp=x;
				x=x->left;
				delete(temp);
			}
			else
			{
				Node* succ=minimum(x->right);
				int t=succ->key;
				succ->key=val;
				x->key=t;
				x->right=del(x->right,val);
			}
			return x;
		}
	}
	void inorderRec(Node* x)
	{
		if(x==NULL)
			return;
		inorderRec(x->left);
		cout<<x->key<<' ';
		inorderRec(x->right);
	}
	void inorder()
	{
		inorderRec(root);
		cout<<'\n';
	}
	void preorderRec(Node* x)
	{
		if(x==NULL)
			return;
		cout<<x->key<<' ';
		preorderRec(x->left);
		preorderRec(x->right);
	}
	void preorder()
	{
		preorderRec(root);
		cout<<'\n';
	}
};
int main()
{
	Tree* tree=new Tree();
	tree->insert(11);
	tree->insert(2);
	tree->insert(9);
	tree->insert(13);
	tree->insert(57);
	tree->insert(25);
	tree->insert(1);
	tree->insert(17);
	tree->insert(90);
	tree->insert(3);
	tree->inorder();
	tree->preorder();
	Node* x=tree->search(11);
	tree->root=tree->del(tree->root,x->key);
	tree->inorder();
	tree->preorder();
	return 0;
}