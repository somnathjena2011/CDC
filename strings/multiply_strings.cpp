#include<bits/stdc++.h>
using namespace std;
string multiply(string& A,string& B)
{
	if(A=="0"||B=="0")
		return "0";
	if(A=="1")
		return B;
	if(B=="1")
		return A;
	int n=A.size();
	int m=B.size();
	vector<int> res(n+m,0);
	int d1,d2,p1,p2,i,j,s,c;
	p1=0;
	for(i=n-1;i>=0;i--)
	{
		c=0;d1=A[i]-'0';p2=0;
		for(j=m-1;j>=0;j--)
		{
			d2=B[j]-'0';
			s=d1*d2+c+res[p1+p2];
			res[p1+p2]=s%10;
			c=s/10;
			p2++;
		}
		if(c>0)
			res[p1+p2]+=c;
		p1++;
	}
	i=n+m-1;
	while(i>=0&&res[i]==0)
		i--;
	if(i<0)
		return "0";
	string ans;
	while(i>=0)
	{
		ans.push_back((char)(res[i]+'0'));
		i--;
	}
	return ans;
}
int main()
{
	string A,B;
	cin>>A;
	cin>>B;
	cout<<multiply(A,B)<<'\n';
	return 0;
}