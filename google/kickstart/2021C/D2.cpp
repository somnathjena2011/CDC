#include<bits/stdc++.h>
using namespace std;
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
int geq(char a,char b)
{
	if(a=='+')
		return b=='+';
	else if(a=='*')
		return b=='*'||b=='+';
}
string operate(string a,string b,char op)
{
	switch(op){
		case '*': return multiply(a,b);
		case '+': return add(a,b);
	}
}
string evaluate(string expr)
{
	if(expr.size()==0)
		return "0";
	stack<string> values;
	stack<char> ops;
	int len=expr.size();
	int i,j;
	string num="";char op;string a="",b="";
	for(i=0;i<len;i++)
	{
		if(expr[i]==' ')
			continue;
		if(expr[i]=='(')
			ops.push('(');
		else if(isdigit(expr[i]))
		{
			num="";
			j=i;
			while(j<len&&isdigit(expr[j]))
			{
				num.push_back(expr[j]);
				j++;
			}
			i=j;i--;
			values.push(num);
		}
		else if(expr[i]==')')
		{
			while(!ops.empty()&&ops.top()!='(')
			{
				a=values.top();
				values.pop();
				b=values.top();
				values.pop();
				op=ops.top();
				ops.pop();
				values.push(operate(b,a,op));
			}
			if(!ops.empty())
				ops.pop();
		}
		else
		{
			while(!ops.empty()&&ops.top()!='('&&geq(ops.top(),expr[i]))
			{
				a=values.top();
				values.pop();
				b=values.top();
				values.pop();
				op=ops.top();
				ops.pop();
				values.push(operate(b,a,op));
			}
			ops.push(expr[i]);
		}
	}
	while(!ops.empty())
	{
		a=values.top();
		values.pop();
		b=values.top();
		values.pop();
		op=ops.top();
		ops.pop();
		values.push(operate(b,a,op));
	}
	return values.top();
}
int main()
{
	int t,n,i,j,k,l,c,rt,lf,f;
	string exprs[100],res[100];
	int ans[100];
	cin>>t;
	string str,lft,rgt,mid,num;
	char op;
	int s,e;
	for(c=1;c<=t;c++)
	{
		string large="1";
		for(i=0;i<99;i++)
			large.push_back('0');
		cin>>n;
		for(i=0;i<n;i++)
			cin>>exprs[i];
		map<pair<string,string>,string> mp;
		map<string,int> mp2;
		for(i=0;i<n;i++)
		{
			l=exprs[i].size();
			f=0;
			for(j=0;j<l;j++)
			{
				if(exprs[i][j]=='#')
				{
					if(isdigit(exprs[i][j-1]))
					{
						for(k=j-1;k>=0;k--)
						{
							if(isdigit(exprs[i][k]))
								s=k;
							else
								break;
						}
					}
					else
					{
						rt=1;lf=0;
						k=j-2;s=j-1;
						while(k>=0&&lf!=rt)
						{
							if(exprs[i][k]=='(')
								++lf;
							else if(exprs[i][k]==')')
								++rt;
							s=k;
							k--;
						}
					}
					if(isdigit(exprs[i][j+1]))
					{
						for(k=j+1;k<l;k++)
						{
							if(isdigit(exprs[i][k]))
								e=k;
							else
								break;
						}
					}
					else
					{
						rt=0;lf=1;
						k=j+2;e=j+1;
						while(k<l&&lf!=rt)
						{
							if(exprs[i][k]=='(')
								++lf;
							else if(exprs[i][k]==')')
								++rt;
							s=k;
							k++;
						}
					}
					f=j;
					break;
				}
			}
			if(f)
			{
				lft=exprs[i].substr(s,f-s);
				rgt=exprs[i].substr(f+1,e-f);
				lft=evaluate(lft);
				rgt=evaluate(rgt);
				if(mp.find({lft,rgt})!=mp.end())
					num=mp[{lft,rgt}];
				else
				{
					large=add(large,"1");
					mp[{lft,rgt}]=large;
					num=large;
				}
				str=exprs[i].substr(0,s)+num+exprs[i].substr(e+1,l-(e+1));
				exprs[i]=str;
			}
		}
		k=1;
		for(i=0;i<n;i++)
		{
			res[i]=evaluate(exprs[i]);
			if(mp2.find(res[i])==mp2.end())
			{
				mp2[res[i]]=k;ans[i]=k;k++;
			}
			else
				ans[i]=mp2[res[i]];
		}
		cout<<"Case #"<<c<<": ";
		for(i=0;i<n;i++)
			cout<<ans[i]<<' ';
		cout<<'\n';
	}
	return 0;
}