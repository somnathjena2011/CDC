#include<bits/stdc++.h>
using namespace std;
class Parent
{
protected:
	int id;
};

class Child: public Parent
{
public:
	void setId(int id)
	{
		this->id=id;
	}
	void dispId()
	{
		cout<<"id = "<<id<<'\n';
	}
};
int main()
{
	Child ob;
	ob.setId(5);
	ob.dispId();
	return 0;
}