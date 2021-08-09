#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long int
#define ll long long int
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define mem memset
#define ff first
#define ss second
#define loop0(i,n) for(i=0;i<n;i++)
#define loop1(i,n) for(i=1;i<=n;i++)
#define rloop0(i,n) for(i=n-1;i>=0;i--)
#define rloop1(i,n) for(i=n;i>0;i--)
#define sloop0(i,n,s) for(i=0;i<n;i+=s)
string multiply(string num1, string num2)
{
    int len1 = num1.size();
    int len2 = num2.size();
    if (len1 == 0 || len2 == 0)
    return "0";
    vector<int> result(len1 + len2, 0);
    int i_n1 = 0;
    int i_n2 = 0;
    for (int i=len1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
        i_n2 = 0;       
        for (int j=len2-1; j>=0; j--)
        {
            int n2 = num2[j] - '0';
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
            carry = sum/10;
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
        i_n1++;
    }
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
    i--;
    if (i == -1)
    return "0";
    string s = "";
     
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
 
    return str;
}
int precedence(char op){
    if(op == '+'||op == '-')
    return 1;
    if(op == '*'||op == '/')
    return 2;
    return 0;
}
string applyOp(string a, string b, char op){
    switch(op){
        case '+': return findSum(a,b);
        case '*': return multiply(a,b);
    }
}
string evaluate(string tokens){
    int i;
    stack <string> values;
    stack <char> ops;
     
    for(i = 0; i < tokens.length(); i++){
        if(tokens[i] == ' ')
            continue;
        else if(tokens[i] == '('){
            ops.push(tokens[i]);
        }
        else if(tokens[i]>='0'&&tokens[i]<='9'){
            string val = "";
            while(i < tokens.length() &&
                        (tokens[i]>='0'&&tokens[i]<='9'))
            {
                val.pb(tokens[i]);
                i++;
            }
             
            values.push(val);
              i--;
        }
        else if(tokens[i] == ')')
        {
            while(!ops.empty() && ops.top() != '(')
            {
                string val2 = values.top();
                values.pop();
                 
                string val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
            if(!ops.empty())
               ops.pop();
        }
        else
        {
            while(!ops.empty() && precedence(ops.top())
                                >= precedence(tokens[i])){
                string val2 = values.top();
                values.pop();
                 
                string val1 = values.top();
                values.pop();
                 
                char op = ops.top();
                ops.pop();
                 
                values.push(applyOp(val1, val2, op));
            }
             
            // Push current token to 'ops'.
            ops.push(tokens[i]);
        }
    }
     
    // Entire expression has been parsed at this
    // point, apply remaining ops to remaining
    // values.
    while(!ops.empty()){
        string val2 = values.top();
        values.pop();
                 
        string val1 = values.top();
        values.pop();
                 
        char op = ops.top();
        ops.pop();
                 
        values.push(applyOp(val1, val2, op));
    }
     
    // Top of 'values' contains result, return it.
    return values.top();
}
int main()
{
	int t,n,i,j,k,l,c,x,f,s,en;
	cin>>t;
	for(c=1;c<=t;c++)
	{
		cin>>n;
		string e[n];int ans[n]={0};
		for(i=0;i<n;i++)
			cin>>e[i];
		map<pair<string,string>,string> mp;
		unordered_map<string,set<int>> mp2;
		string large="1";
		for(i=0;i<99;i++)
			large.pb('0');
		for(i=0;i<n;i++)
		{
			l=e[i].length();
			f=-1;
			for(j=0;j<l;j++)
			{
				if(e[i][j]=='#')
				{
					f=j;
					break;
				}
			}
			if(f>=0)
			{
				string str;
				for(j=f-1;j>=0;j--)
				{
					if(e[i][j]>='0'&&e[i][j]<='9')
						s=j;
					else
						break;
				}
				for(j=f+1;j<l;j++)
				{
					if(e[i][j]>='0'&&e[i][j]<='9')
						en=j;
					else
						break;
				}
				string lft,mid1,rgt,mid2;
				lft=e[i].substr(0,s);
				rgt=e[i].substr(en+1,l-en-1);
				mid1=e[i].substr(s,f-s);
				mid2=e[i].substr(f+1,en-f);
				if(mp.find({mid1,mid2})!=mp.end())
					str=lft+mp[{mid1,mid2}]+rgt;
				else
				{
					str=lft+large+rgt;
					mp[{mid1,mid2}]=large;
					large=findSum(large,"1");
				}
				e[i]=str;
			}
		}
		for(i=0;i<n;i++)
		{
			string res=evaluate(e[i]);
			if(mp2.find(res)!=mp2.end())
				mp2[res].insert(i);
			else
			{
				set<int> stt;stt.insert(i);
				mp2[res]=stt;
			}
		}
		i=1;
		for(auto pr:mp2)
		{
			set<int> indices=pr.second;
			for(auto ind:indices)
				ans[ind]=i;
			i++;
		}
		int sets[n]={0};
		i=1;
		for(j=0;j<n;j++)
		{
			if(sets[j]==0)
			{
				for(k=j;k<n;k++)
				{
					if(ans[k]==ans[j])
						sets[k]=i;
				}
				i++;
			}
		}
		cout<<"Case #"<<c<<": ";
		for(i=0;i<n;i++)
			cout<<sets[i]<<' ';
		cout<<'\n';
	}
	return 0;
}