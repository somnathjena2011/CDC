#include<iostream>
using namespace std;
namespace N {
	int val = 11;
	inline namespace M {
		int val = 10;
	}
}
int main()
{
	cout<<N::val<<'\n';//error (ambiguous reference)
	return 0;
}