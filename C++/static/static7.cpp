#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	static int x;
};
static int y;
int A::x=0;
int main(){
	A a;
	cout<<A::x<<'\n';
	cout<<y<<'\n';
	return 0;
}