#include<bits/stdc++.h>
using namespace std;
unordered_map<char,int> pref;
bool geq(char op1,char op2)
{
	return pref[op1]>=pref[op2];
}
string convert(string in)
{
	string ans;
	int n=in.size();
	int i,j;
	stack<char> ops;
	char op;
	for(i=0;i<n;i++)
	{
		if(in[i]==' ')
			continue;
		if(in[i]=='(')
			ops.push(in[i]);
		else if(isdigit(in[i]))
		{
			j=i;
			while(j<n&&isdigit(in[j]))
			{
				ans.push_back(in[j]);
				j++;
			}
			ans+=" ";
			i=j-1;
		}
		else if(in[i]==')')
		{
			while(!ops.empty()&&ops.top()!='(')
			{
				ans.push_back(ops.top());
				ops.pop();
				ans.push_back(' ');
			}
			if(!ops.empty())
				ops.pop();
		}
		else
		{
			while(!ops.empty()&&ops.top()!='('&&geq(ops.top(),in[i]))
			{
				ans.push_back(ops.top());
				ops.pop();
				ans.push_back(' ');
			}
			ops.push(in[i]);
		}
	}
	while(!ops.empty()&&ops.top()!='(')
	{
		ans.push_back(ops.top());
		ops.pop();
		ans.push_back(' ');
	}
	return ans;
}
int main()
{
	pref['+']=1;pref['-']=1;
	pref['*']=2;pref['/']=2;pref['%']=2;
	string in;
	getline(cin,in);
	string post=convert(in);
	cout<<post<<'\n';
	return 0;
}