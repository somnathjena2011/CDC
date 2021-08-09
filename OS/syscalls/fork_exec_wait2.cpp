#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
int main()
{
	printf("Parent\n");
	pid_t pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"Error in forking\n");
		return 0;
	}
	else if(pid==0)
	{
		printf("In child process\n");
		return 0;
	}
	else
	{
		int status;
		//pid_t wpid=wait(&status);
		pid_t wpid;
		do{
			wpid=wait(&status);
		}while(!WIFSIGNALED(status)&&!WIFEXITED(status));
		printf("cpid=%d\n",pid);
		printf("wpid=%d\n",wpid);
		printf("status returned=%d\n",status);
		return 0;
	}
}