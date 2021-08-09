#include<bits/stdc++.h>
using namespace std;
string add(string& x,string& y,int b)
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
	string x,y;
	int b;
	cin>>x;
	cin>>y;
	cin>>b;
	string sum=add(x,y,b);
	cout<<sum<<'\n';
	return 0;
}