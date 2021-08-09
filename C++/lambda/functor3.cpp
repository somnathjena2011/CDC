//using functor with state to add elements of vector
#include<bits/stdc++.h>
using namespace std;
struct adder:public unary_function<int,void>
{
	int sum;
	adder():sum(0)
	{
		cout<<"Called\n";
	}
	void operator()(int x)
	{
		sum+=x;
	}
};
int main()
{
	vector<int> v={4,2,7,5,6};
	adder ob;
	adder result=for_each(v.begin(),v.end(),ob);
	adder ob2;
	cout<<result.sum<<'\n';
	if(&result==&ob)
		cout<<"Same\n";
	cout<<ob2.sum<<'\n';
	return 0;
}