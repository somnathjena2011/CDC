#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s,p;//string and pattern
	cin>>s;
	cin>>p;
	int n=s.size();
	int m=p.size();
	int pre[m];
	pre[0]=0;
	int k=0;
	int i;
	for(i=1;i<m;i++)
	{
		while(k>0&&p[k]!=p[i])
			k=pre[k-1];
		if(p[k]==p[i])
			k++;
		pre[i]=k;
	}
	vector<int> indices;
	k=0;
	for(i=0;i<n;i++)
	{
		while(k>0&&s[i]!=p[k])
			k=pre[k-1];
		if(p[k]==s[i])
			k++;
		if(k==m)
		{
			indices.push_back(i-m+1);
			k=pre[m-1];
		}
	}
	for(int ind:indices)
		cout<<ind<<' ';
	cout<<'\n';
	return 0;
}