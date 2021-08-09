#include<bits/stdc++.h>
using namespace std;
bool geq(char a,char b)
{
	switch(a)
	{
		case '+': return b=='+'||b=='-';
		case '-': return b=='+'||b=='-';
		case '*': return true;
		case '/': return true;
	}
	return false;
}
bool isOperand(char a)
{
	return a!='('&&a!=')'&&a!='+'&&a!='-'&&a!='*'&&a!='/';
}
string convert(string exp)
{
	stack<char> ops;
	int len=exp.size();
	int i,j;
	string ans="";
	for(i=0;i<len;i++)
	{
		if(exp[i]==' ')
			continue;
		else if(exp[i]=='(')
			ops.push('(');
		else if(exp[i]==')')
		{
			while(!ops.empty()&&ops.top()!='(')
			{
				ans.push_back(ops.top());
				ops.pop();
			}
			if(!ops.empty())
				ops.pop();
		}
		else if(isOperand(exp[i]))
		{
			j=i;
			while(j<len&&isOperand(exp[j]))
			{
				ans.push_back(exp[j]);
				j++;
			}
			i=j;i--;
		}
		else
		{
			while(!ops.empty()&&ops.top()!='('&&geq(ops.top(),exp[i]))
			{
				ans.push_back(ops.top());
				ops.pop();
			}
			ops.push(exp[i]);
		}
	}
	while(!ops.empty())
	{
		ans.push_back(ops.top());
		ops.pop();
	}
	return ans;
}
int main()
{
	string exp;
	cin>>exp;
	string postfix=convert(exp);
	cout<<postfix<<'\n';
	return 0;
}