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
int compare(string& a,string& b)
{
	if(a.length()<b.length())
		return 1;
	else if(a.length()==b.length()&&a<b)
		return 1;
	return 0;
}
string getCons(string& no,string st)
{
	string a=st;
	string ret=st;
	while(ret.length()<no.length())
	{
		a=to_string(stol(a)+1);
		ret=ret+a;
	}
	return ret;
}
int main()
{
	ll t,n,y,x,i;
	cin>>t;
	loop1(x,t)
	{
		cin>>y;
		string no=to_string(y);
		if(no.length()==1)
		{
			cout<<"Case #"<<x<<": "<<"12\n";
			continue;
		}
		string no2;
		string ans=to_string(LONG_MAX);
		string str;
		for(i=1;i<=no.length()/2;i++)
		{
			str=getCons(no,no.substr(0,i));
			//cout<<"i="<<i<<" str="<<str<<'\n';
			if(compare(no,str)&&compare(str,ans))
				ans=str;
			no2 = to_string(stol(no.substr(0,i))+1);
			str=getCons(no,no2);
			//cout<<"i="<<i<<" str2="<<str<<'\n';
			if(compare(no,str)&&compare(str,ans))
				ans=str;
		}
		no2="";
		no2.pb('1');
		for(i=1;i<=no.length();i++)
			no2.pb('0');
		string no3;
		for(i=1;i<=no2.length()/2;i++)
		{
			str=getCons(no2,no2.substr(0,i));
			//cout<<"i="<<i<<" str="<<str<<'\n';
			if(compare(no,str)&&compare(str,ans))
				ans=str;
			no3 = to_string(stol(no2.substr(0,i))+1);
			str=getCons(no2,no3);
			//cout<<"i="<<i<<" str2="<<str<<'\n';
			if(compare(no,str)&&compare(str,ans))
				ans=str;
		}
		cout<<"Case #"<<x<<": "<<ans<<'\n';
	}
	return 0;
}