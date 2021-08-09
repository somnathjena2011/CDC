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
bool isOperator(char a)
{
	return a=='+'||a=='*';
}
string multiply(string a,string b)
{
	if(a.size()==0||b.size()==0)
		return "0";
	int len1=a.size();
	int len2=b.size();
	int i,j,ind1,ind2;
	vector<int> res(len1+len2,0);
	int carry,sum,d1,d2;
	ind1=ind2=0;
	for(i=len2-1;i>=0;i--)
	{
		carry=0;d2=b[i]-'0';
		ind1=0;
		for(j=len1-1;j>=0;j--)
		{
			d1=a[j]-'0';
			sum=d1*d2+carry+res[ind1+ind2];
			res[ind1+ind2]=sum%10;
			carry=sum/10;
			ind1++;
		}
		if(carry)
			res[ind1+ind2]=carry;
		ind2++;
	}
	i=len1+len2-1;
	while(i>=0&&res[i]==0)
		i--;
	if(i<0)
		return "0";
	string ans="";
	while(i>=0)
	{
		ans+=to_string(res[i]);
		i--;
	}
	return ans;
}
string add(string a,string b)
{
	if(a.size()<b.size())
		swap(a,b);
	string ans="";
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int d1,d2,sum,carry=0;
	int i,j;
	int len1=a.size();int len2=b.size();
	for(i=0;i<len1;i++)
	{
		if(i>len2-1)
			d2=0;
		else
			d2=b[i]-'0';
		d1=a[i]-'0';
		sum=d1+d2+carry;
		j=sum%10;
		carry=sum/10;
		ans.push_back((char)(j+'0'));
	}
	if(carry)
		ans.push_back((char)(carry+'0'));
	reverse(ans.begin(),ans.end());
	return ans;
}
string calc(string a,string b,char op)
{
	switch(op)
	{
		case '+':return add(a,b);
		case '*':return multiply(a,b);
		default: return "0";
	}
}
string evaluate(string expr)
{
	int len=expr.size();
	if(len==0)return "0";
	int i,j;
	string ans;
	stack<string> values;
	char op;
	string n1,n2,n;
	for(i=0;i<len;i++)
	{
		if(expr[i]==' ')
			continue;
		if(isOperator(expr[i]))
		{
			n2=values.top();
			values.pop();
			n1=values.top();
			values.pop();
			n=calc(n1,n2,expr[i]);
			values.push(n);
		}
		else
		{
			j=i;n="";
			while(j<len&&isdigit(expr[j]))
			{
				n.push_back(expr[j]);
				j++;
			}
			values.push(n);
			i=j;i--;
		}
	}
	return values.top();
}
int main()
{
	string expr;
	getline(cin,expr);
	string ans=evaluate(expr);
	cout<<ans<<'\n';
	return 0;
}