#include<bits/stdc++.h>
using namespace std;
string multiply(string& a,string& b)
{
	int n=a.size();
	int m=b.size();
	if(n==0||m==0)
		return "0";
	if(a=="0"||b=="0")
		return "0";
	if(a=="1")
		return b;
	if(b=="1")
		return a;
	vector<int> res(n+m,0);
	int ind1,ind2,i,j,carry,sum,d1,d2;
	ind1=ind2=0;
	for(i=m-1;i>=0;i--)
	{
		ind1=0;carry=0;d1=b[i]-'0';
		for(j=n-1;j>=0;j--)
		{
			d2=a[j]-'0';
			sum=res[ind1+ind2]+carry+d1*d2;
			carry=sum/10;
			res[ind1+ind2]=sum%10;
			ind1++;
		}
		if(carry>0)
			res[ind1+ind2]+=carry;
		ind2++;
	}
	string ans="";
	i=n+m-1;
	while(i>=0&&res[i]==0)
		i--;
	if(i<0)
		return "0";
	while(i>=0)
	{
		ans=ans+to_string(res[i]);
		i--;
	}
	return ans;
}
string add(string a,string b)
{
	int n=a.size();
	int m=b.size();
	if(m==0||b=="0")
		return a;
	if(n==0||a=="0")
		return b;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	string ans;
	int carry=0,sum=0;int i; int d1,d2;
	for(i=0;i<max(n,m);i++)
	{
		if(i>=n)
			d1=0;
		else
			d1=a[i]-'0';
		if(i>=m)
			d2=0;
		else
			d2=b[i]-'0';
		sum=d1+d2+carry;
		carry=sum/10;
		sum=sum%10;
		ans.push_back(sum+'0');
	}
	if(carry>0)
		ans.push_back(carry+'0');
	reverse(ans.begin(),ans.end());
	return ans;
}
struct Node{
	Node* left;
	Node* right;
	Node* parent;
	string val;
	char op;
	bool isVal;
	Node(string val):val(val),left(NULL),right(NULL),isVal(true),parent(NULL){};
	Node(char op):op(op),left(NULL),right(NULL),isVal(false),val(""),parent(NULL){};
};
int p[255];
Node* build(string expr,Node*& hash)
{
	stack<Node*> nodeStack;
	stack<char> opStack;
	p['+']=1;p['*']=2;p['#']=3;
	char op;string val1,val2,val;
	Node* node=NULL;Node* n1=NULL;Node* n2=NULL;
	int n=expr.size();int i;int j;
	for(i=0;i<n;i++)
	{
		if(expr[i]==' ')
			continue;
		else if(expr[i]=='(')
			opStack.push(expr[i]);
		else if(isdigit(expr[i]))
		{
			j=i;val="";
			while(j<n&&isdigit(expr[j]))
			{
				val.push_back(expr[j]);
				j++;
			}
			i=j;i--;
			node=new Node(val);
			nodeStack.push(node);
		}
		else if(expr[i]=='+'||expr[i]=='*'||expr[i]=='#')
		{
			while(!opStack.empty()&&opStack.top()!='('&&p[opStack.top()]>=p[expr[i]])
			{
				n2=nodeStack.top();
				nodeStack.pop();
				n1=nodeStack.top();
				nodeStack.pop();
				op=opStack.top();
				opStack.pop();
				node=new Node(op);
				if(n1->val!=""&&n2->val!="")
				{
					if(op=='+')
						val=add(n1->val,n2->val);
					else if(op=='*')
						val=multiply(n1->val,n2->val);
					else
					{
						hash=node;
						val="";
					}
				}
				else
					val="";
				node->left=n1;node->right=n2;
				n1->parent=node;n2->parent=node;
				node->val=val;
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
				if(n1->val!=""&&n2->val!="")
				{
					if(op=='+')
						val=add(n1->val,n2->val);
					else if(op=='*')
						val=multiply(n1->val,n2->val);
					else
					{
						hash=node;
						val="";
					}
				}
				else
					val="";
				node->left=n1;node->right=n2;
				node->val=val;
				n1->parent=node;n2->parent=node;
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
		if(n1->val!=""&&n2->val!="")
		{
			if(op=='+')
				val=add(n1->val,n2->val);
			else if(op=='*')
				val=multiply(n1->val,n2->val);
			else
			{
				hash=node;
				val="";
			}
		}
		else
			val="";
		node->left=n1;node->right=n2;
		node->val=val;
		n1->parent=node;n2->parent=node;
		nodeStack.push(node);
	}
	return nodeStack.top();
}
void postorder(Node* root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		if(root->isVal)
			cout<<root->val<<' ';
		else
			cout<<root->op<<' ';
	}
}
int main()
{
	int t,n,x,i,j,k;
	cin>>t;
	for(x=1;x<=t;x++)
	{
		cin>>n;
		string expr[n];
		for(i=0;i<n;i++)
			cin>>expr[i];
		map<vector<string>,int> mp;
		string a,b,c,d;
		int ans[n];k=1;
		for(i=0;i<n;i++)
		{
			Node* hash=NULL;
			Node* root=build(expr[i],hash);
			if(hash)
			{
				hash->left->left=NULL;
				hash->left->right=NULL;
				hash->right->left=NULL;
				hash->right->right=NULL;
				hash->left->isVal=true;
				hash->right->isVal=true;
				if(hash->parent&&hash->parent->right==hash)
				{
					Node* right=hash;
					Node* left=hash->parent->left;
					Node* parent=hash->parent;
					parent->left=hash;
					parent->right=left;
				}
				if(hash->parent==NULL||hash->parent->left==hash)
				{
					if(hash==root||hash->parent->op=='+')
					{
						Node* right=new Node("1");
						Node* mult=new Node('*');
						right->parent=mult;
						mult->right=right;
						mult->left=hash;
						mult->parent=hash->parent;
						if(hash->parent)
							hash->parent->left=mult;
						hash->parent=mult;
					}
					if(hash->parent->op=='*')
					{
						Node* right=new Node("0");
						Node* add=new Node('+');
						right->parent=add;
						add->right=right;
						add->left=hash->parent;
						if(hash->parent->parent)
							hash->parent->parent->left=add;
						add->parent=hash->parent->parent;
						hash->parent->parent=add;
					}
					while(hash->parent->parent&&hash->parent->parent->parent)
					{
						Node* grand=hash->parent->parent;
						Node* great=grand->parent;
						if(great->right==grand)
						{
							Node* left=great->left;
							great->left=grand;
							great->right=left;
						}
						if(great->parent)
						{
							Node* super=great->parent;
							if(super->right==great)
							{
								Node* left=super->left;
								super->left=great;
								super->right=left;
							}
						}
						if(great->op=='+')
						{
							Node* super=great->parent;
							string v1=grand->right->val;
							string v2=great->right->val;
							string v=add(v1,v2);
							grand->right->val=v;
							grand->parent=super;
							if(super)
								super->left=grand;
							//free(great->right);
							//free(great);
						}
						else if(great->op=='*')
						{
							Node* super=great->parent;
							Node* parent=hash->parent;
							string v1=grand->right->val;
							string v2=great->right->val;
							string v=multiply(v1,v2);
							grand->right->val=v;
							grand->parent=super;
							if(super)
								super->left=grand;
							//free(great->right);
							//free(great);
							v1=parent->right->val;
							v=multiply(v1,v2);
							parent->right->val=v;
						}
					}
					a=hash->left->val;
					b=hash->right->val;
					c=hash->parent->right->val;
					d=hash->parent->parent->right->val;
					if(c=="0")
						a=b="0";
				}
			}
			else
			{
				a=b=c="0";
				d=root->val;
			}
			vector<string> vec{a,b,c,d};
			if(mp.find(vec)!=mp.end())
				ans[i]=mp[vec];
			else
			{
				mp[vec]=k;
				ans[i]=k;
				k++;
			}
		}
		cout<<"Case #"<<x<<": ";
		for(i=0;i<n;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}