#include<bits/stdc++.h>
using namespace std;
class IntWrap
{
public:
	int i;
	IntWrap(int i):i(i){}
	friend IntWrap operator+(IntWrap& a,IntWrap& b)
	{
		return IntWrap(a.i+b.i);
	}
};
template<typename T>
T add(T& a,T& b)
{
	return a+b;
}
template<typename T1,typename T2>
T1 sum(T1& a,T2& b)
{
	return a+b;
}
template<typename T1,typename T2,typename R>
R sum2(T1& a,T2& b)
{
	return a+b;
}
int main()
{
	IntWrap a(4);
	IntWrap b(5);
	IntWrap c=add(a,b);
	cout<<c.i<<'\n';
	int i=3;double j=3.2;
	cout<<sum(i,j)<<'\n';
	cout<<sum(j,i)<<'\n';
	int k=4;
	//cout<<sum2(i,k)<<'\n';//COULD NOT DEDUCE TEMPLATE PARAMETER R
	cout<<sum2<int,int,int>(i,k)<<'\n';
	return 0;
}