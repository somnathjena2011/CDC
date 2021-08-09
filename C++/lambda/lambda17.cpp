#include<bits/stdc++.h>
using namespace std;
int main()
{
	float F,C;
	cin>>F;
	C=[](float F){return (F-32)/1.8;}(F);
	cout<<C<<'\n';
	return 0;
}