#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<errno.h>
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)//Error
	{
		fprintf(stderr,"Fork failed\n");
		exit(EXIT_FAILURE);
	}
	else if(pid==0)//Child
	{
		execlp("/bin/ls","ls",NULL);
	}
	else//parent
	{
		wait(NULL);
		printf("Child completed\n");
	}
	return 0;
}