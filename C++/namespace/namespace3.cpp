#include<iostream>
using namespace std;
namespace ns1 {
	int val=5;
	namespace ns2 {
		int val=6;
	}
}
namespace alias = ns1::ns2;
int main()
{
	cout<<ns1::val<<'\n';
	cout<<alias::val<<'\n';
	return 0;
}