#include<bits/stdc++.h>
using namespace std;
string multiply(string a,string b)
{
	int len1=a.size();
	int len2=b.size();
	if(len1==0||len2==0)
		return "0";
	vector<int> res(len1+len2,0);
	int ind1,ind2;
	ind1=ind2=0;
	int i,j;
	int carry,sum;int d1,d2;
	for(i=len2-1;i>=0;i--)
	{
		carry=sum=0;ind1=0;d2=b[i]-'0';
		for(j=len1-1;j>=0;j--)
		{
			d1=a[j]-'0';
			sum=d1*d2+res[ind1+ind2]+carry;
			carry=sum/10;
			res[ind1+ind2]=sum%10;
			++ind1;
		}
		if(carry>0)
			res[ind1+ind2]+=carry;
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
		ans=ans+to_string(res[i]);
		i--;
	}
	return ans;
}
int main()
{
	string str1 = "1235421415454545454545454544";
    string str2 = "1714546546546545454544548544544545";
    string sign="";
    if(str1.size()>0&&str2.size()>0&&
    	((str1[0]=='-'&&str2[0]!='-')||(str1[0]!='-'&&str2[0]=='-')))
    	sign="-";
    if(str1.size()>0&&str1[0]=='-')
    	str1=str1.substr(1);
    if(str2.size()>0&&str2[0]=='-')
    	str2=str2.substr(1);
    string ans=sign+multiply(str1,str2);
    cout<<ans<<'\n';
    return 0;
}