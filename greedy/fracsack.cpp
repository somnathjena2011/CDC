#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,p,w,k;
	cin>>n>>k;
	int profits[n],weights[n];
	for(i=0;i<n;i++)
		cin>>profits[i]>>weights[i];
	pair<double,int> rate[n];
	for(i=0;i<n;i++)
		rate[i]={(double)profits[i]/weights[i],i};
	sort(rate,rate+n,greater<pair<double,int>>());
	double rem=(double)k;
	double prof=0;
	double currw;
	for(i=0;i<n;i++)
	{
		if(rem<=0.0)
			break;
		if((double)weights[rate[i].second]<=rem)
			currw=(double)weights[rate[i].second];
		else
			currw=rem;
		rem-=currw;
		prof+=(rate[i].first*currw);
	}
	cout<<prof<<'\n';
	return 0;
}