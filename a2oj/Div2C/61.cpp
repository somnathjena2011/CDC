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
int main()
{
	string no;
	cin>>no;
	int rem=0;int div=7;
	int freq[10]={0};
	int i,j,co;
	loop0(i,no.size())
		++freq[no[i]-'0'];
	string no2="";
	for(i=1;i<=9;i++)
	{
		if(i==1||i==6||i==8||i==9)
			co=freq[i]-1;
		else
			co=freq[i];
		loop0(j,co)
		no2.pb('0'+i);
	}
	string no3=no2+"0000";
	int n=no3.size();int d;
	loop0(i,n)
	{
		d=no3[i]-'0';
		d=rem*10+d;
		rem=d%div;
	}
	int req=(div-rem)%7;
	string rems[7]={"1869","1968","1689","6198","1698","1986","1896"};
	no2+=rems[req];
	loop0(i,freq[0])
	no2.pb('0');
	cout<<no2<<'\n';
	return 0;
}