//recursive factorial
#include<bits/stdc++.h>
using namespace std;
int main()
{
	function<int(int)> f;
	f = [&](int n){
		if(n<=1)return 1;
		return n*f(n-1);
	};
	cout<<f(5)<<'\n';
	return 0;
}