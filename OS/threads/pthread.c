#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int sum;

void* runner(void* param);

int main(int argc, char const *argv[])
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_create(&tid,&attr,runner,(void*)argv[1]);
	pthread_join(tid,NULL);
	printf("%d\n",sum);
	return 0;
}

void* runner(void* param)
{
	int n=atoi((char*)param);
	for(int i=1;i<=n;i++)
		sum+=i;
	pthread_exit(0);
}