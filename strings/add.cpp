#include<bits/stdc++.h>
using namespace std;
string add(string a,string b)
{
	if(a.size()<b.size())
		swap(a,b);
	string ans="";
	int len1=a.size();
	int len2=b.size();
	int i,j;
	int sum=0;int carry=0;int d,d1,d2;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	for(i=0;i<len1;i++)
	{
		if(i>len2-1)
			d2=0; 
		else
			d2=b[i]-'0';
		d1=a[i]-'0';
		sum=carry+d1+d2;
		d=sum%10;
		ans.push_back((char)(d+'0'));
		carry=sum/10;
	}
	if(carry>0)
		ans.push_back((char)(carry+'0'));
	reverse(ans.begin(),ans.end());
	return ans;
}
int main()
{
	string s1="12";
	string s2="198111";
	cout<<add(s1,s2)<<'\n';
	return 0;
}