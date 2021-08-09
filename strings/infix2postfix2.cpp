#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> pref;
//true if op1 has higher or equal preference to op2
bool geq(char op1,char op2)
{
	return pref[op1]>=pref[op2];
}
string convert(string expr)
{
	int n=expr.size();
	string ans;
	int i,j;
	stack<char> ops;
	for(i=0;i<n;i++)
	{
		if(expr[i]==' ')
			continue;
		else if(expr[i]=='(')
			ops.push('(');
		else if(expr[i]==')')
		{
			while(!ops.empty()&&ops.top()!='(')
			{
				ans.push_back(ops.top());
				ops.pop();
				ans+=" ";
			}
			if(!ops.empty())
				ops.pop();
		}
		else if(isdigit(expr[i]))
		{
			j=i;
			while(j<n&&isdigit(expr[j]))
			{
				ans.push_back(expr[j]);
				j++;
			}
			ans+=" ";
			i=j-1;
		}
		else
		{
			while(!ops.empty()&&ops.top()!='('&&geq(ops.top(),expr[i]))
			{
				ans.push_back(ops.top());
				ops.pop();
				ans+=" ";
			}
			ops.push(expr[i]);
		}
	}
	while(!ops.empty())
	{
		ans.push_back(ops.top());
		ops.pop();
		ans+=" ";
	}
	return ans;
}
int main()
{
	pref['+']=pref['-']=1;
	pref['/']=pref['*']=pref['%']=2;
	string expr;
	getline(cin,expr);
	string post=convert(expr);
	cout<<post<<'\n';
	return 0;
}