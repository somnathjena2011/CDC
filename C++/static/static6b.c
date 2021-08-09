#include<stdio.h>
/*
this is declared static in 6a
so wduring linking error will be caused
stating undefined reference tox
as static variable/function are only accessible in the same file
where they are declared
*/
extern int x;
extern void fun();
int main()
{
	fun();
	printf("x=%d\n",x);
	return 0;
}