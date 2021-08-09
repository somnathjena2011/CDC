#include<stdio.h>
#include<stdlib.h>

int comp(const void* a,const void* b)
{
	return (*(const int*)a>*(const int*)b);
}

int main()
{
	int arr[5]={3,4,1,2,7};
	qsort((void*)arr,5,sizeof(int),comp);
	for(int i=0;i<5;i++)
		printf("%d ",arr[i]);
	printf("\n");
	return 0;
}