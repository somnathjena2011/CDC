#include<bits/stdc++.h>
using namespace std;
string simplify(string& path)
{
	int n=path.length();
	vector<string> paths;
	for(int i=0;i<n;i++)
	{
		if(isalnum(path[i]))
		{
			string p="";
			while(i<n&&path[i]!='/')
				p+=path[i++];
			paths.push_back(p);
		}
		else if(path[i]=='.')
		{
			if(i+1<n&&path[i+1]!='/'&&i+2<n&&path[i+2]!='/')
			{
				string p="";
				while(i<n&&path[i]!='/')
					p+=path[i++];
				paths.push_back(p);
			}
			else if(i+1<n&&path[i+1]=='.')
			{
				if(!paths.empty())
					paths.pop_back();
			}
		}
	}
	if(paths.empty())
		return "/";
	string ans="";
	for(string& p:paths)
		ans+="/"+p;
	return ans;
}
int main()
{
	int n,i;
	cin>>n;
	string paths[n];
	for(i=0;i<n;i++)
	{
		cin>>paths[i];
		cout<<simplify(paths[i])<<'\n';
	}
	return 0;
}