#include<bits/stdc++.h>
using namespace std;
struct Node
{
	map<char,Node*> mp;
	bool eow;
	Node():eow(false){}
};
void insert(Node* root,string word)
{
	Node* curr=root;
	for(char c:word)
	{
		if(curr->mp.find(c)==curr->mp.end())
			curr->mp[c]=new Node();
		curr=curr->mp[c];
	}
	curr->eow=true;
}
bool search(Node* root,string word)
{
	Node* curr=root;
	for(char c:word)
	{
		if(curr->mp.find(c)==curr->mp.end())
			return false;
		curr=curr->mp[c];
	}
	return curr->eow;
}
bool pre_search(Node* root,string pre)
{
	Node* curr=root;
	for(char c:pre)
	{
		if(curr->mp.find(c)==curr->mp.end())
			return false;
		curr=curr->mp[c];
	}
	return true;
}
bool delUtil(Node* root,string word,int i)
{
	if(!root)return false;
	if(i==word.size())
	{
		root->eow=false;
		return root->mp.empty();
	}
	Node* node=root->mp[word[i]];
	if(!node)return false;
	bool shouldDel=delUtil(node,word,i+1);
	if(shouldDel)
		root->mp.erase(word[i]);
	return root->mp.empty();
}
void del(Node* root,string word)
{
	delUtil(root,word,0);
}
int main()
{
	Node* root=new Node();
	insert(root,"abcd");
	insert(root,"abgl");
	insert(root,"cdf");
	insert(root,"abcde");
	insert(root,"lmn");
	cout<<pre_search(root,"ab")<<'\n';
	cout<<pre_search(root,"lo")<<'\n';
	cout<<search(root,"lmn")<<'\n';
	cout<<search(root,"ab")<<'\n';
	del(root,"abcd");
	cout<<search(root,"abcde")<<'\n';
	del(root,"abcde");
	del(root,"abgl");
	cout<<search(root,"abcde")<<'\n';
	return 0;
}