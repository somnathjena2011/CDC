#include<bits/stdc++.h>
using namespace std;
int main()
{
	function<int(const string&)> fn;
	fn = [](const string& s){return s.size();};
	int size=fn("ppd");
	cout<<size<<'\n';
	return 0;
}