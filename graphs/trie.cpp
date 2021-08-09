#include<bits/stdc++.h>
using namespace std;
struct Node{
	map<char,Node*> mp;
	bool eow;
	Node():eow(false){}
};
class Trie{
public:
	Node* root;
	Trie()
	{
		root=new Node();
	}
	void insert(string word)
	{
		int l=word.length();
		Node* curr=root;
		for(int i=0;i<l;i++)
		{
			if(!curr->mp[word[i]])
			{
				Node* node=new Node();
				curr->mp[word[i]]=node;
			}
			curr=curr->mp[word[i]];
		}
		curr->eow=true;
	}
	bool search(string word)
	{
		int l=word.length();
		Node* curr=root;
		for(int i=0;i<l;i++)
		{
			if(!curr->mp[word[i]])
				return false;
			curr=curr->mp[word[i]];
		}
		return curr->eow;
	}
	bool preSearch(string pre)
	{
		int l=pre.length();
		Node* curr=root;
		for(int i=0;i<l;i++)
		{
			if(!curr->mp[pre[i]])
				return false;
			curr=curr->mp[pre[i]];
		}
		return true;
	}
	bool delUtil(Node* curr,string word,int i)
	{
		if(i==word.length())
		{
			if(!curr->eow)
				return false;
			curr->eow=false;
			return curr->mp.empty();
		}
		char ch=word[i];
		Node* node=curr->mp[ch];
		if(node==NULL)
			return false;
		bool shouldDel = delUtil(node,word,i+1);
		if(shouldDel)
		{
			curr->mp.erase(ch);
			return curr->mp.empty();
		}
		return false;
	}
	void del(string word)
	{
		delUtil(root,word,0);
	}
};
int main()
{
	Trie* trie=new Trie();
	trie->insert("abcd");
	trie->insert("abgl");
	trie->insert("cdf");
	trie->insert("abcde");
	trie->insert("lmn");
	cout<<trie->preSearch("ab")<<'\n';
	cout<<trie->preSearch("lo")<<'\n';
	cout<<trie->search("lmn")<<'\n';
	cout<<trie->search("ab")<<'\n';
	cout<<trie->search("lmn")<<'\n';
	trie->del("abcd");
	cout<<trie->search("abcde")<<'\n';
	trie->del("abcde");
	trie->del("abgl");
	cout<<trie->preSearch("ab")<<'\n';
	return 0;
}