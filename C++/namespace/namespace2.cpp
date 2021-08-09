#include<iostream>
#include "namespace2.h"
using namespace std;
int main()
{
	cout<<foo::val<<'\n';
	cout<<val<<'\n';
	int val=7;
	cout<<val<<'\n';
	return 0;
}