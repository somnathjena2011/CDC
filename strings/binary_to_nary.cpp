#include<bits/stdc++.h>
using namespace std;
string add(string x,string y,int b)
{
	if(x=="0")return y;
	if(y=="0")return x;
	int n=x.size();
	int m=y.size();
	int d1,d2,s,c=0;
	string ans;
	for(int i=1;i<=max(n,m);i++)
	{
		d1=n-i>=0?x[n-i]-'0':0;
		d2=m-i>=0?y[m-i]-'0':0;
		s=c+d1+d2;
		ans.push_back((char)(s%b+'0'));
		c=s/b;
	}
	if(c>0)
		ans.push_back((char)(c+'0'));
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	string x;
	int b;
	cin>>x;
	cin>>b;
	string ans="0";
	int n=x.size();
	int i;
	for(i=0;i<n;i++)
	{
		string d;d+=x[i];
		ans=add(add(ans,ans,b),d,b);
	}
	cout<<ans<<'\n';
	return 0;
}