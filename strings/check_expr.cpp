#include<bits/stdc++.h>
using namespace std;
bool adjSign(string& s,int i)
{
	if(i==0)
		return true;
	if(s[i-1]=='-')
		return false;
	return true;
}
void eval(string& s,vector<int>& v,bool add)
{
	stack<bool> st;
	st.push(true);
	int i=0;
	while(s[i]!='\0')
	{
		if(s[i]=='+'||s[i]=='-')
		{
			i++;
			continue;
		}
		if(s[i]=='(')
		{
			if(adjSign(s,i))
				st.push(st.top());
			else
				st.push(!st.top());
		}
		else if(s[i]==')')
			st.pop();
		else
		{
			if(add)
			{
				if(st.top())
					v[s[i]-'a']+=(adjSign(s,i)?1:-1);
				else
					v[s[i]-'a']+=(adjSign(s,i)?-1:1);
			}
			else
			{
				if(st.top())
					v[s[i]-'a']+=(adjSign(s,i)?-1:1);
				else
					v[s[i]-'a']+=(adjSign(s,i)?1:-1);
			}
		}
		i++;
	}
}
bool check(string& e1,string& e2)
{
	vector<int> v(26,0);
	eval(e1,v,true);
	eval(e2,v,false);
	for(int i=0;i<26;i++)
		if(v[i]!=0)
			return false;
	return true;
}
int main()
{
	string e1,e2;
	cin>>e1;
	cin>>e2;
	cout<<check(e1,e2)<<'\n';
	return 0;
}