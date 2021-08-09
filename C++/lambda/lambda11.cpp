#include<bits/stdc++.h>
using namespace std;
struct trace
{
	int i;
	trace():i(0){cout<<"Constructor\n";}
	trace(const trace& ob)
	{
		cout<<"Copy Constructor\n";
	}
	~trace()
	{
		cout<<"Destructor\n";
	}
	trace& operator=(trace&)
	{
		cout<<"Assignment operator\n";
		return *this;
	}
};
int main()
{
	trace t;
	auto m1=[=]{int i=t.i;};
	auto m2=m1;
	return 0;
}