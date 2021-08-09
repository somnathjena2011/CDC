#include<bits/stdc++.h>
using namespace std;
int main()
{
	int i=7;
	[](int &v){v*=6;}(i);
	cout<<i<<'\n';
	return 0;
}