#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
struct Node{
	ll l;
	ll r;
	Node* left;
	Node* right;
	ll height;
	Node(ll l,ll r):l(l),r(r),left(NULL),right(NULL),height(1){}
};
bool empty(Node* root)
{
	if(root==NULL)
		return true;
	else
		return false;
}
Node* lower_search(Node* root,ll key)
{
	Node* curr=root;
	Node* ans=NULL;
	while(curr!=NULL)
	{
		if(curr->l<=key&&key<=curr->r)
			return curr;
		else if(key < curr->l)
			curr=curr->left;
		else
		{
			ans=curr;
			curr=curr->right;
		}
	}
	return ans;
}
Node* upper_search(Node* root,ll key)
{
	Node* curr=root;
	Node* ans=NULL;
	while(curr!=NULL)
	{
		if(curr->l<=key&&key<=curr->r)
			return curr;
		else if(key < curr->l)
		{
			ans=curr;
			curr=curr->left;
		}
		else
			curr=curr->right;
	}
	return ans;
}
Node* maximum(Node* x)
{
	Node* c=x;
	while(c&&c->right!=NULL)
		c=c->right;
	return c;
}
Node* minimum(Node* x)
{
	Node* c=x;
	while(c&&c->left!=NULL)
		c=c->left;
	return c;
}
ll height(Node* x)
{
	if(x!=NULL)
		return x->height;
	else
		return 0;
}
ll getBalance(Node* node)
{
	if(node==NULL)
		return 0;
	return height(node->left)-height(node->right);
}
Node* rightRotate(Node* y)
{
	Node* x=y->left;
	Node* z=NULL;
	if(x)
	{
		z=x->right;
		x->right=y;
		y->left=z;
		y->height= max(height(y->left),height(y->right))+1;
		x->height= max(height(x->left),height(x->right))+1;
		return x;
	}
	return y;
}
Node* leftRotate(Node* x)
{
	Node* y=x->right;
	Node* z=NULL;
	if(y)
	{
		z=y->left;
		y->left=x;
		x->right=z;
		x->height= max(height(x->left),height(x->right))+1;
		y->height= max(height(y->left),height(y->right))+1;
		return y;
	}
	return x;
}
Node* insert(Node* node,ll l,ll r)
{
	if(node==NULL)
	{
		Node* n=new Node(l,r);
		return n;
	}
	if(r < node->l)
		node->left = insert(node->left, l, r);
	else if(l > node->r)
		node->right = insert(node->right, l, r);
	else
		return node;

	node->height = max(height(node->left),height(node->right))+1;
	ll bal = getBalance(node);
	if(bal>1 && r < node->left->l)
		return rightRotate(node);
	if(bal<-1 && l > node->right->r)
		return leftRotate(node);
	if(bal>1 && l > node->left->r)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(bal<-1 && r < node->right->l)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
Node* del(Node* node,ll l,ll r)
{
	if(node==NULL)
		return node;

	if(r < node->l)
		node->left = del(node->left, l, r);
	else if(l > node->r)
		node->right = del(node->right, l, r);
	else
	{
		if(node->left==NULL || node->right==NULL)
		{
			Node* temp= node->left ? node->left : node->right;
			if(temp==NULL)
			{
				temp=node;
				node=NULL;
			}
			else
				*node = *temp;
			delete(temp);
		}
		else
		{
			Node* temp = minimum(node->right);
			node->l = temp->l;
			node->r = temp->r;
			node->right = del(node->right, temp->l, temp->r);
		}
	}
	if(node==NULL)
		return node;

	node->height = max(height(node->left),height(node->right))+1;
	ll bal=getBalance(node);
	if(bal>1 && getBalance(node->left)>=0)
		return rightRotate(node);
	if(bal>1 && getBalance(node->left)<0)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(bal<-1 && getBalance(node->right)<=0)
		return leftRotate(node);
	if(bal<-1 && getBalance(node->right)>0)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node);
	}
	return node;
}
void inorder(Node* root)
{
	if(!root)
		return;
	inorder(root->left);
	cout<<root->l<<' '<<root->r<<' ';
	inorder(root->right);
}
int main()
{
	ll t,n,m,i,j,x,s,z,l1,l2,r1,r2;
	ll l,r;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>n>>m;
		vector<pair<ll,ll>> sets;
		vector<ll> ans;
		Node* root=NULL;
		for(i=0;i<n;i++)
		{
			cin>>l>>r;
			sets.push_back({l,r});
			root=insert(root,l,r);
		}
		//inorder(root);
		//cout<<'\n';
		sort(sets.begin(),sets.end());
		for(i=0;i<m;i++)
		{
			cin>>s;
			Node* lower=lower_search(root,s);
			Node* upper=upper_search(root,s);
			l1=l2=LONG_MIN;
			r1=r2=LONG_MAX;
			if(lower)
			{
				l1=lower->l;
				l2=lower->r;
			}
			if(upper)
			{
				r1=upper->l;
				r2=upper->r;
			}
			if(s>=l1&&s<=l2)
			{
				z=s;
				if(s==l2)
				{
					if(lower->r==lower->l)
						root=del(root,s,s);
					else
						lower->r--;
				}
				else if(s==l1)
				{
					if(lower->r==lower->l)
						root=del(root,s,s);
					else
						lower->l++;
				}
				else
				{
					ll a=l1;ll b=s-1;
					ll c=s+1;ll d=l2;
					root=del(root,l1,l2);
					if(a<=b)
						root=insert(root,a,b);
					if(c<=d)
						root=insert(root,c,d);
				}
			}
			else if(s>=r1&&s<=r2)
			{
				z=s;
				if(s==r1)
				{
					if(upper->r==upper->l)
						root=del(root,s,s);
					else
						upper->l++;
				}
				else if(s==r2)
				{
					if(upper->r==upper->l)
						root=del(root,s,s);
					else
						upper->r--;
				}
				else
				{
					ll a=r1;ll b=s-1;
					ll c=s+1;ll d=r2;
					root=del(root,r1,r2);
					if(a<=b)
						root=insert(root,a,b);
					if(c<=d)
						root=insert(root,c,d);
				}
			}
			else
			{
				ll dl;
				if(l2==LONG_MIN)
				{
					z=r1;
					if(r1==r2)
						root=del(root,r1,r2);
					else
						upper->l++;
				}
				else if(r1==LONG_MAX)
				{
					z=l2;
					if(l2==l1)
						root=del(root,l1,l2);
					else
						lower->r--;
				}
				else
				{
					ull d1=(ull)s-(ull)l2;
					ull d2=(ull)r1-(ull)s;
					if(d1<=d2)
					{
						z=l2;
						if(l2==l1)
							root=del(root,l1,l2);
						else
							lower->r--;
					}
					else
					{
						z=r1;
						if(r1==r2)
							root=del(root,r1,r2);
						else
							upper->l++;
					}
				}				
			}
			ans.push_back(z);
			//inorder(root);
			//cout<<'\n';
		}
		cout<<"Case #"<<x<<": ";
		for(ll el:ans)
			cout<<el<<' ';
		cout<<'\n';
	}
	return 0;
}