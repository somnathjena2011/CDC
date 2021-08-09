#include<bits/stdc++.h>
using namespace std;
struct functor
{
	string s;
	functor(const string& s):s(s){}
	int operator()()  {return s.size();}
};

int main()
{
	functor f("ppd");
	function<int()> fn;
	fn = ref(f);
	int size=fn();
	cout<<size<<'\n';
	return 0;
}