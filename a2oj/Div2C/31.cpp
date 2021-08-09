#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define rloop0(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>0;i--)
#define sloop0(i,n,s) for(i=0;i<n;i+=s)
struct Node{
	int key;
	Node* left;
	Node* right;
	Node(int key):key(key),left(NULL),right(NULL){}
};
void inorder(Node* node)
{
	if(node==NULL)
		return;
	inorder(node->left);
	cout<<node->key<<'\n';
	inorder(node->right);
}
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int i;
	Node* root=new Node(1);
	Node* curr=root;
	int key=2;
	for(i=0;i<n-1;i++)
	{
		Node* node=new Node(key);
		if(s[i]=='l')
			curr->left=node;
		else
			curr->right=node;
		key++;
		curr=node;
	}
	inorder(root);
	return 0;
}