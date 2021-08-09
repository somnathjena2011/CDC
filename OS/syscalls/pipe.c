#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
int main()
{
	int fd[2];
	//fd[0]-read fd[1]-write
	if(pipe(fd)<0)
	{
		printf("Error in opening pipe\n");
		return 1;
	}
	pid_t pid=fork();
	if(pid==0)
	{
		close(fd[0]);
		int x;
		printf("Input a number\n");
		scanf("%d",&x);
		write(fd[1],&x,sizeof(int));
		close(fd[1]);
	}
	else
	{
		close(fd[1]);
		int y;
		read(fd[0],&y,sizeof(int));
		close(fd[0]);
		printf("Number input=%d\n",y);
	}
	return 0;
}