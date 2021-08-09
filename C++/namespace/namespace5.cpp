#include<iostream>
void error()
{
	//cout is not defined in this scope
	//cout<<"Error\n";
}
int main()
{
	using namespace std;
	cout<<"Hello\n";
	return 0;
}