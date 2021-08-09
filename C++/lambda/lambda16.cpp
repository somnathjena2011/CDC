#include<bits/stdc++.h>
using namespace std;
int a;
function<bool(int)> returnClosure()
{
	static int b=0,c=0;
	return [](int x){
		cout<<a<<'\n';
		return a*x*x+b*x+c==0;
	};
}
int main()
{
	auto f=returnClosure();
	a=10;
	if(f(0))
		cout<<"true\n";
	else
		cout<<"false\n";
	return 0;
}