/*
capture
->default all by value
->default all by reference
->specific identifiers by value &/ reference, this
->default and specific
*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t=0;
	vector<int> v={1,3,4,2,3};
	//all by reference
	for_each(v.begin(),v.end(),[&](int i){t++;});
	cout<<t<<'\n';	
	//all by value, gives error
	t=0;
	//gives error, by-value capture can't be modified 
	//by non-mutable lambda
	//for_each(v.begin(),v.end(),[=](int i){t++;});
	cout<<t<<'\n';
}