#include<bits/stdc++.h>
using namespace std;
template<typename T>
void Swap(T& x,T& y)
{
	T t=x;
	x=y;
	y=t;
}
class Uncopyable
{
public:
	void operator=(const Uncopyable& u)
	{
		
	}
};
class IntWrap:public Uncopyable
{
	int data;
};
int main()
{
	IntWrap a,b;
	Swap<IntWrap>(a,b);
	//Link error- undefined reference to operator=
	return 0;
}