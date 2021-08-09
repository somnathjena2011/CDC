/*
Differences between constructor & function:
1. Constructor has same name as class
2. Constructor has no return type
3. Constructor is automatically called when we create an object
4. Constructor should always be public
5. If we do not specify a constructor compiler provides a default

*/
#include<bits/stdc++.h>
using namespace std;
class A
{
public:
	int a;
	A(int a)
	{
		this->a=a;
	}
};
int main()
{
	A a;
	return 0;
}