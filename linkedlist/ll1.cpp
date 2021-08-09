#include<bits/stdc++.h>
using namespace std;
struct Node {
	int key;
	Node* next;
	Node(int key):key(key),next(NULL){}
};
class List{
public:
	Node* head;
	List():head(NULL){}
	void insBegin(int key);
	void insEnd(int key);
	void ins(int key,int n);
	void delBegin();
	void delEnd();
	void del(int n); 
	void print();
};
void List::insBegin(int key)
{
	Node* temp=new Node(key);
	temp->next=this->head;
	this->head=temp;
}
void List::insEnd(int key)
{
	Node* temp1=new Node(key);
	if(this->head==NULL)
	{
		this->head=temp1;
		return;
	}
	Node* temp2=this->head;
	while(temp2->next!=NULL)
		temp2=temp2->next;
	temp2->next=temp1;
}
void List::ins(int key,int n)
{
	if(n<1)
		return;
	if(n==1)
	{
		this->insBegin(key);
		return;
	}
	Node* temp1=new Node(key);
	Node* temp2=this->head;
	int i=0;
	while(temp2&&i<n-2)
	{
		temp2=temp2->next;
		i++;
	}
	if(temp2==NULL)
		return;
	temp1->next=temp2->next;
	temp2->next=temp1;
}
void List::delBegin()
{
	if(this->head)
	{
		Node* temp=this->head->next;
		delete(this->head);
		this->head=temp;
	}
}
void List::delEnd()
{
	if(this->head==NULL)
		return;
	if(this->head->next==NULL)
	{
		delete(this->head);
		this->head=NULL;
		return;
	}
	Node* temp=this->head;
	while(temp->next->next!=NULL)
		temp=temp->next;
	delete(temp->next);
	temp->next=NULL;
}
void List::del(int n)
{
	if(n==0)
		return;
	if(n==1)
		this->delBegin();
	Node* temp1=this->head;
	if(temp1==NULL||temp1->next==NULL)
		return;
	int i=0;
	while(temp1->next->next!=NULL&&i<n-2)
	{
		i++;
		temp1=temp1->next;
	}
	if(i<n-2)
		return;
	Node* temp2=temp1->next->next;
	delete(temp1->next);
	temp1->next=temp2;
}
void List::print()
{
	Node* temp=this->head;
	while(temp!=NULL)
	{
		cout<<temp->key<<' ';
		temp=temp->next;
	}
	cout<<'\n';
}
int main()
{
	List* l=new List();
	int t,k,n;
	do{
		cin>>t;
		switch(t)
		{
			case 0:
				//ins begin
				cin>>k;
				l->insBegin(k);
				break;
			case 1:
				//ins end
				cin>>k;
				l->insEnd(k);
				break;
			case 2:
				//ins at nth position
				cin>>k>>n;
				l->ins(k,n);
				break;
			case 3:
				//del begin
				l->delBegin();
				break;
			case 4:
				//del end
				l->delEnd();
				break;
			case 5:
				//del at nth position
				cin>>n;
				l->del(n);
				break;
		}
		l->print();
	}while(t<6);
}