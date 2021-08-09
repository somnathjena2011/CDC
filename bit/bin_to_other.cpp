#include<bits/stdc++.h>
using namespace std;
string add(string a,string b,int base)
{
	if(a=="0")
		return b;
	if(b=="0")
		return a;
	int n=a.size();
	int m=b.size();
	vector<int> sum(max(n,m)+1,0);
	int i=n-1;int j=m-1;
	int k=0;
	int d,d1,d2,c=0,s;
	while(i>=0||j>=0)
	{
		d1=i>=0?a[i]-'0':0;
		d2=j>=0?b[j]-'0':0;
		i--;j--;
		s=c+d1+d2;
		d=s%base;
		c=s/base;
		sum[k]=d;
		k++;
	}
	if(c)
		sum[k]=c;
	i=max(n,m);
	while(i>=0&&sum[i]==0)
		i--;
	if(i<0)
		return "0";
	string ans="";
	while(i>=0)
	{
		ans.push_back((char)(sum[i]+'0'));
		i--;
	}
	return ans;
}
int main()
{
	string binary;
	cin>>binary;
	int base;
	cin>>base;
	string ans="0";
	int n=binary.size();
	for(int i=0;i<n;i++)
	{
		string bit;
		bit.push_back(binary[i]);
		ans=add(add(ans,ans,base),bit,base);
	}
	cout<<ans<<'\n';
	return 0;
}