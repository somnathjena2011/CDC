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
double angle(int x,int y)
{
	double xx=(double)x;
	double yy=(double)y;
	double xp=abs(xx);
	double yp=abs(yy);
	double pi = 2.0*acos(0.0);
	double pid= 180.0/pi;
	double theta,degree;
	if(xp<=0)
		theta = pi/2;
	else
		theta = atan(yp/xp);
	degree = theta*pid;
	if(xx>=0&&yy>=0)
		degree=degree;
	else if(xx<0&&yy>=0)
		degree=180.0-degree;
	else if(xx<=0&&yy<=0)
		degree=180.0+degree;
	else
		degree=360.0-degree;
	return degree;
}
int main()
{
	int n;
	cin>>n;int i,j,a,b;
	int x,y;
	double angles[n];
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		angles[i]=angle(x,y);
	}
	sort(angles,angles+n);
	double ans=360.0;
	double a1,a2,d;
	if(abs(angles[0]-angles[n-1])<0.000001)
	{
		cout<<0<<'\n';
		return 0;
	}
	for(i=0;i<n;i++)
	{
		a1=angles[i];
		a2=angles[(i-1+n)%n];
		if(a2>a1)
			d=abs(a1-a2);
		else
			d=360.0-abs(a1-a2);
		if(d<ans)
			ans=d;
	}
	cout.precision(12);
	cout<<ans<<'\n';
	return 0;
}