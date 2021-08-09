#include<bits/stdc++.h>
using namespace std;
int findSign(string& a,int i)
{
	if(i==0)
		return 1;
	if(a[i-1]=='-')
		return -1;
	return 1;
}
void eval(string& a,vector<int>& allSigns)
{
	int n=a.size();
	int sign=1;
	int i;
	stack<int> signs;
	int s,t;
	int global=1;
	for(i=0;i<n;i++)
	{
		if(a[i]=='+'||a[i]=='-')
			continue;
		if(a[i]=='(')
		{
			s=findSign(a,i);
			global*=s;
			signs.push(s);
		}
		else if(a[i]==')')
		{
			s=signs.top();
			global*=s;
			signs.pop();
		}
		else
		{
			s=findSign(a,i);
			t=global*s;
			allSigns[a[i]-'a']=t;
		}
	}
}
int check(string& a,string& b)
{
	vector<int> val1(26,0);
	vector<int> val2(26,0);
	eval(a,val1);
	eval(b,val2);
	cout<<"val1\n";
	for(int i=0;i<26;i++)
		cout<<val1[i]<<' ';
	cout<<'\n';
	cout<<"val2\n";
	for(int i=0;i<26;i++)
		cout<<val2[i]<<' ';
	cout<<'\n';
	for(int i=0;i<26;i++)
		if(val1[i]!=val2[i])
			return 0;
	return 1;
}
int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	cout<<check(a,b)<<'\n';
	return 0;
}