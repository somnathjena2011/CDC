#include<unistd.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
int main()
{
	int* shm;
	key_t key=48;
	int shmid;
	shmid=shmget(key,sizeof(int)*2,IPC_CREAT|0666);
	shm=(int*)shmat(shmid,NULL,0);
	shm[0]=2;shm[1]=5;
	printf("ppid: %d\n",getpid());
	pid_t pid=fork();
	if(pid<0)
	{
		fprintf(stderr,"Error in forking\n");
		return 1;
	}
	else if(pid==0)
	{
		printf("cpid: %d\n",getpid());
		shm=(int*)shmat(shmid,NULL,0);
		printf("%d\n",shm[0]+shm[1]);
		shmdt(shm);
		shmctl(shmid,IPC_RMID,NULL);
		return 0;
	}
	shmdt(shm);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}