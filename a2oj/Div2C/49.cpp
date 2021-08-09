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
int main()
{
	ll q;
	cin>>q;
	ll n=q;
	ll no=0;
	ll i;
	ll c=0;
	ll p1,p2;
	ll pp1,pp2;
	ll two=0;
	ll three=0;
	while(n%2==0)
	{
		++c;
		if(c==2)
		{
			two=1;
			pp1=2;
		}
		if(c==3)
			three=2;
		n/=2;
		no=1;
		p1=2;
	}
	for(i=3;i*i<=n;i+=2)
	{
		if(n%i==0)
		{
			++no;c=0;
			if(no==1)
				p1=i;
			else if(no==2)
				p2=i;
			while(n%i==0)
			{
				++c;
				if(c==2&&two==0)
				{
					pp1=i;
					two=1;
				}
				else if(c==2&&two==1)
				{
					pp2=i;
					two=2;
				}
				if(c==3)
					three=i;
				n/=i;
			}
		}
	}
	if(n>2)
		++no; 
	if(two==2)
	{
		cout<<1<<'\n';
		cout<<pp1*pp1<<'\n';
		return 0;
	}
	else if(two==1)
	{
		if(three!=0)
		{
			cout<<1<<'\n';
			cout<<three*three<<'\n';
			return 0;
		}
		if(no==1)
			cout<<2<<'\n';
		else
		{
			cout<<1<<'\n';
			cout<<pp1*pp1<<'\n';
		}
		return 0;
	}
	if(no==2)
		cout<<2<<'\n';
	else if(no<=1)
	{
		cout<<1<<'\n';
		cout<<0<<'\n';
	}
	else
	{
		cout<<1<<'\n';
		cout<<p1*p2<<'\n';
	}
	return 0;
}