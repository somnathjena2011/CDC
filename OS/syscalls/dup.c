#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
int main()
{
	char* args[] = {"ls","-l","-a",0};
	char* file   = args[0];
	int redirect_fd = open("redirect.txt",O_CREAT|O_TRUNC|O_WRONLY);
	printf("redirect_fd=%d\n",redirect_fd);
	dup2(redirect_fd,STDOUT_FILENO);
	close(redirect_fd);
	if(execvp(file,args)==-1)
		fprintf(stderr,"Error executing %s\n",file);
	printf("done\n");
	return 0;
}