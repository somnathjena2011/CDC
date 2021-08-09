#include "functor6.h"
#include<stdio.h>
extern void (*f)();
void h()
{
	printf("India\n");
}
int main()
{
	f=h;
	g();
	return 0;
}