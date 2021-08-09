#include<bits/stdc++.h>
using namespace std;
struct Node{
	char* symbol;
	int frequency;
	Node* next;
	Node* left;
	Node* right;
	Node(char* symbol,int frequency)
	{
		this->symbol=(char*)malloc((strlen(symbol)+1)*sizeof(char));
		strcpy(this->symbol,symbol);
		this->frequency=frequency;
		this->next=NULL;
		this->left=NULL;
		this->right=NULL;
	}
};
bool compare(char* sym1,char* sym2,int f1,int f2)
{
	if(f1<f2)
		return true;
	else if(f1==f2)
	{
		if((sym1[0]=='N'&&sym2[0]!='N')||(sym1[0]>='a'&&sym2[0]<='9'))
			return true;
		else if(sym1[0]=='N'&&sym2[0]=='N')
		{
			int x=0;int y=0;
			int i;
			for(i=1;i<strlen(sym1);i++)
				x=x*10+sym1[i]-'0';
			for(i=1;i<strlen(sym2);i++)
				y=y*10+sym1[i]-'0';
			return x<y;
		}
		else if(sym1[0]!='N'&&sym2[0]!='N')
		{
			if(sym1[0]>='a'&&sym2[0]>='a')
				return sym1[0]<sym2[0];
			else if(sym1[0]<='9'&&sym2[0]<='9')
				return sym1[0]<sym2[0];
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}
Node* insert(Node* head,Node* node)
{
	if(!head)
		return node;
	else
	{
		Node* curr=head;
		Node* prev=NULL;int f=0;
		while(curr)
		{
			if(compare(node->symbol,curr->symbol,node->frequency,curr->frequency))
			{
				f=1;
				if(prev)
				{
					prev->next=node;
					node->next=curr;
				}
				else
				{
					node->next=curr;
					head=node;
				}
				break;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
		if(!f)
			prev->next=node;
		return head;
	}
}
void print(Node* head)
{
	Node* curr=head;
	while(curr)
	{
		cout<<curr->symbol<<' '<<curr->frequency<<' ';
		curr=curr->next;
	}
	cout<<'\n';
}
void TreeTraverse(Node* root,char* C,char* H[36])
{
	if(!root->left&&!root->right)
	{
		char c=root->symbol[0];
		int i;
		if(c>='a')
			i=c-'a';
		else
			i=c-'0'+26;
		strcpy(H[i],C);
	}
	else
	{
		char *C1=(char*)malloc((strlen(C)+2)*sizeof(char));
		strcpy(C1,C);
		strcat(C1,"0");
		TreeTraverse(root->left,C1,H);
		char *C2=(char*)malloc((strlen(C)+2)*sizeof(char));
		strcpy(C2,C);
		strcat(C2,"1");
		TreeTraverse(root->right,C2,H);
	}
}
void preorder(Node* root,FILE* fp)
{
	if(!root)
		return;
	fprintf(fp,"%s ",root->symbol);
	preorder(root->left,fp);
	preorder(root->right,fp);
}
void decode(char* encodedMessage,char* decodedOutput,char* H[36])
{
	//decodedOutput=(char*)malloc((strlen(encodedMessage)+1)*sizeof(char));
	int i=0;
	int n=strlen(encodedMessage);int j,k,l;char c;int x,y,z;int f;z=0;
	while(i<n)
	{
		for(j=0;j<36;j++)
		{
			l=strlen(H[j]);
			if(i+l-1>=n)
				continue;
			f=1;
			for(x=i,y=0;x<n,y<l;x++,y++)
			{
				if(encodedMessage[x]!=H[j][y])
				{
					f=0;
					break;
				}
			}
			if(f)
			{
				if(j<26)
					c=(char)(j+'a');
				else
					c=(char)(j+'0'-26);
				decodedOutput[z]=c;
				z++;
				i=i+l;
				break;
			}
		}
	}
}
int main()
{
	FILE* fin=fopen("log.txt","r");
	int n,i,j;
	fscanf(fin,"%d",&n);
	char* words[n];
	for(i=0;i<n;i++)
		words[i]=(char*)malloc(100*sizeof(char));
	for(i=0;i<n;i++)
		fscanf(fin,"%s",words[i]);
	int freq[36]={0};
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(words[i]);j++)
		{
			if(words[i][j]>='a')
				++freq[words[i][j]-'a'];
			else
				++freq[words[i][j]-'0'+26];
		}
	}
	Node* head=NULL;
	for(i=0;i<36;i++)
	{
		char arr[2];
		if(i<26)
			arr[0]=(char)('a'+i);
		else
			arr[0]=(char)('0'+i-26);
		arr[1]='\0';
		Node* node=new Node(arr,freq[i]);
		if(!head)
			head=node;
		else
		{
			Node* curr=head;
			Node* prev=NULL;int f=0;
			while(curr)
			{
				if(compare(node->symbol,curr->symbol,freq[i],curr->frequency))
				{
					f=1;
					if(prev)
					{
						prev->next=node;
						node->next=curr;
					}
					else
					{
						node->next=curr;
						head=node;
					}
					break;
				}
				else
				{
					prev=curr;
					curr=curr->next;
				}
			}
			if(!f)
				prev->next=node;
		}
	}
	FILE* fout=(FILE*)fopen("out.txt","w");
	Node* curr=NULL;
	curr=head;
	while(curr)
	{
		fprintf(fout,"%s %d ",curr->symbol,curr->frequency);
		curr=curr->next;
	}
	fprintf(fout,"\n");
	int no=1;
	curr=NULL;
	//print(head);
	for(i=1;i<36;i++)
	{
		Node* first=head;
		Node* second=head->next;
		char* name=(char*)malloc(100*sizeof(char));
		name[0]='N';
		int d=0;int di;
		int x=no;
		while(x)
		{
			++d;
			x/=10;
		}
		x=no;name[d+1]='\0';
		while(x)
		{
			di=x%10;
			x/=10;
			name[d]=(char)('0'+di);
			d--;
		}
		no++;
		Node* node=new Node(name,first->frequency+second->frequency);
		node->left =first;
		node->right=second;
		head=second->next;
		first->next=NULL;second->next=NULL;
		head=insert(head,node);
		//print(head);
	}
	char* H[36];
	for(i=0;i<36;i++)
		H[i]=(char*)malloc(100*sizeof(char));
	char* C=(char*)malloc(100*sizeof(char));
	C[0]='\0';
	TreeTraverse(head,C,H);
	preorder(head,fout);
	fprintf(fout,"\n");
	for(i=0;i<36;i++)
	{
		char c;
		if(i<26)
			c=(char)('a'+i);
		else
			c=(char)('0'+i-26);
		fprintf(fout,"%c %s\n",c,H[i]);
	}
	FILE* encode=(FILE*)fopen("encode.txt","r");
	fscanf(encode,"%d",&n);
	char str[100];
	for(i=0;i<n;i++)
	{
		fscanf(encode,"%s",str);
		int l=strlen(str);
		for(j=0;j<l;j++)
		{
			char c=str[j];
			int k;
			if(c>='a')
				k=c-'a';
			else
				k=c-'0'+26;
			fprintf(fout,"%s",H[k]);
		}
		fprintf(fout,"\n");
	}
	FILE* dec=(FILE*)fopen("decode.txt","r");
	fscanf(dec,"%d",&n);
	for(i=0;i<n;i++)
	{
		char str[100];
		fscanf(dec,"%s",str);
		char* outt=(char*)malloc(100*sizeof(char));
		decode(str,outt,H);
		fprintf(fout,"%s\n",outt);
	}
	fclose(fout);
	fclose(encode);
	fclose(dec);
	fclose(fin);
	return 0;
}