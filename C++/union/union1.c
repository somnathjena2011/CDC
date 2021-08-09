#include<bits/stdc++.h>
using namespace std;
typedef enum Tag
{
	FIELD1,
	FIELD2
}Tag;
typedef union Union
{
	int i1;
	int i2;
	Tag tag;
	Union(Tag tag,int i)
	{
		tag=tag;
		switch(tag)
		{
			case FIELD1:
			i1=i;break;
			case FIELD2:
			i2=i;break;
		}
	}
}Union;
typedef struct Sum
{
	Tag tag;
	Union un;
	Sum(Tag tag,int i):tag(tag),un(tag,i){}
}Sum;
int myCase(Sum sum)
{
	switch(sum.tag)
	{
		case FIELD1:return sum.un.i1;
		case FIELD2:return sum.un.i2;
	}
}
int main()
{
	Sum sum1(FIELD1,5);
	Sum sum2(FIELD2,7);
	cout<<myCase(sum1)<<'\n';
	cout<<myCase(sum2)<<'\n';
	return 0;
}