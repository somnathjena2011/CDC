#include<bits/stdc++.h>
using namespace std;
struct Node{
	Node* left;
	Node* right;
	char data;
	Node(char data):data(data),left(NULL),right(NULL){};
};
Node* build(string expr)
{
	stack<Node*> nodeStack;
	stack<char> opStack;
	int len=expr.size();
	int i;
	int p[255];
	p['+']=p['-']=1;
	p['*']=p['/']=2;
	p['^']=3;
	p[')']=0;
	Node* node=NULL;
	Node* n1=NULL;
	Node* n2=NULL;
	char op;
	for(i=0;i<len;i++)
	{
		if(expr[i]==' ')
			continue;
		else if(expr[i]=='(')
			opStack.push(expr[i]);
		else if(isalpha(expr[i]))
		{
			node=new Node(expr[i]);
			nodeStack.push(node);
		}
		else if(p[expr[i]]>0)
		{
			while(!opStack.empty()&&
				((expr[i]!='^'&&p[opStack.top()]>=p[expr[i]])||
				(expr[i]=='^'&&p[opStack.top()]>p[expr[i]])))
			{
				n2=nodeStack.top();
				nodeStack.pop();
				n1=nodeStack.top();
				nodeStack.pop();
				op=opStack.top();
				opStack.pop();
				node=new Node(op);
				node->left=n1;
				node->right=n2;
				nodeStack.push(node);
			}
			opStack.push(expr[i]);
		}
		else if(expr[i]==')')
		{
			while(!opStack.empty()&&opStack.top()!='(')
			{
				n2=nodeStack.top();
				nodeStack.pop();
				n1=nodeStack.top();
				nodeStack.pop();
				op=opStack.top();
				opStack.pop();
				node=new Node(op);
				node->left=n1;
				node->right=n2;
				if(op==)
				nodeStack.push(node);
			}
			if(!opStack.empty())
				opStack.pop();
		}
	}
	while(!opStack.empty())
	{
		n2=nodeStack.top();
		nodeStack.pop();
		n1=nodeStack.top();
		nodeStack.pop();
		op=opStack.top();
		opStack.pop();
		node=new Node(op);
		node->left=n1;
		node->right=n2;
		nodeStack.push(node);	
	}
	return nodeStack.top();
}
void postOrder(Node* root)
{
	if(root==NULL)
		return;
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data;
}
int main()
{
	string expr;
	cin>>expr;
	Node* root=build(expr);
	postOrder(root);
	cout<<'\n';
	return 0;
}