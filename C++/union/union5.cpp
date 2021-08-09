#include<bits/stdc++.h>
using namespace std;
union Union
{
	int i1;
	int i2;
};
struct Struct
{
	union
	{
		int i1;
		int i2;
	};
};
int main()
{
	Union u1;
	u1.i1=4;
	cout<<u1.i1<<' '<<u1.i2<<'\n';
	u1.i2=7;
	cout<<u1.i1<<' '<<u1.i2<<'\n';
	Struct st;
	cout<<st.i1<<' '<<st.i2<<'\n';
	st.i1=2;
	cout<<st.i1<<' '<<st.i2<<'\n';
	return 0;
}