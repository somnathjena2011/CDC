#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
	printf("Started\n");
	char* args[]={"ls","-a","-l",0};
	char* file  =args[0];
	execvp(file,args);
	printf("Ended\n");
	return 0;
}