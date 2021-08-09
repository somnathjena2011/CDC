#include<bits/stdc++.h>
using namespace std;
int main()
{
	auto findFare=[](int dist){
		if(dist<=0)
			cout<<"Invalid\n";
		else if(dist<=12)
			cout<<100<<'\n';
		else if(dist<=16)
			cout<<100+8*(dist-12)<<'\n';
		else if(dist<=20)
			cout<<132+6*(dist-16)<<'\n';
		else
			cout<<156+5*(dist-20)<<'\n';
	};
	int dist;
	cin>>dist;
	findFare(dist);
	return 0;
}