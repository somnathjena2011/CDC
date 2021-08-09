#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<pthread.h>
#include<semaphore.h>
#include<time.h>

#define MAX_QUEUE_SIZE 8
#define MAX_PRIORITY 10
#define MAX_JOB_ID 100000

typedef struct job{
	int job_id;
	int prod_no;
	pthread_t prod_tid;
	int priority;
	int comp_time;
}job;

sem_t mutex,full,empty;

job priority_queue[MAX_QUEUE_SIZE];
int size;
int max_jobs;
int job_completed;
int job_created;

void init_shm(int jobs);

void* produce(void* p);
void* consume(void* p);

int left(int i);
int right(int i);
int parent(int i);
void swap(job* j1,job* j2);
void heapify(int i);
job create_job(int prod_no,pthread_t prod_tid,unsigned int *seed);
void insert_job(job j);
job remove_job();
void print_job(job j);

int main()
{
	int NP,NC,p,c,status;
	scanf("%d %d %d",&NP,&NC,&max_jobs);

	pthread_t producers[NP];
	pthread_t consumers[NC];

	int prod_nos[NP];
	int cons_nos[NC];

	time_t start=time(0);

	pthread_attr_t attr;
	pthread_attr_init(&attr);

	init_shm(max_jobs);

	for(p=0;p<NP;p++)
	{
		prod_nos[p]=p+1;
		status=pthread_create(&producers[p],&attr,produce,(void*)&(prod_nos[p]));
		if(status!=0)
		{
			printf("Error in creating thread. Exitting..\n");
			exit(1);
		}
	}

	for(c=0;c<NC;c++)
	{
		cons_nos[c]=c+1;
		status=pthread_create(&consumers[c],&attr,consume,(void*)&(cons_nos[c]));
		if(status!=0)
		{
			printf("Error in creating thread. Exitting..\n");
			exit(1);
		}
	}

	while(1)
	{
		sem_wait(&mutex);
		if(job_created==max_jobs&&job_completed==max_jobs)
		{
			time_t end=time(0);
			int time_taken=end-start;
			printf("Time taken to run %d jobs:%d\n",max_jobs,time_taken);
			for(int i=0;i<NP;i++)
				pthread_cancel(producers[i]);
			for(int i=0;i<NC;i++)
				pthread_cancel(consumers[i]);
			sem_post(&mutex);
			break;
		}
		sem_post(&mutex);
	}
	sem_destroy(&mutex);
	return 0;
}

void* produce(void* p)
{
	unsigned int seed=time(0)+*((int*)p);
	while(1)
	{
		if(job_created==max_jobs)
			break;
		job j=create_job(*((int*)p),pthread_self(),&seed);
		sleep(rand_r(&seed)%4);
		sem_wait(&empty);
		sem_wait(&mutex);
		if(job_created==max_jobs)
		{
			sem_post(&mutex);
			break;
		}
		if(size<MAX_QUEUE_SIZE)
		{
			insert_job(j);
			printf("Produced job details:\n");
			print_job(j);
			job_created++;
			sem_post(&full);
		}
		sem_post(&mutex);
	}
}

void* consume(void* p)
{
	unsigned int seed=time(0)+*((int*)p);
	while(1)
	{
		if(job_completed==max_jobs)
			break;
		sleep(rand_r(&seed)%4);
		sem_wait(&full);
		sem_wait(&mutex);
		int job_retrieved=0;
		job j;
		if(size>0)
		{
			j=remove_job();
			job_retrieved=1;
		}
		sem_post(&mutex);
		if(job_retrieved)
		{
			printf("Consumed job details\n");
			printf("consumer: %d,",*((int*)p));
			printf("consumer tid: %ld,",pthread_self());
			print_job(j);
			sem_wait(&mutex);
			++job_completed;
			sem_post(&mutex);
			sem_post(&empty);
			sleep(j.comp_time);
		}
	}
}

void init_shm(int jobs)
{
	size=job_completed=job_created=0;
	max_jobs=jobs;

	int sema=sem_init(&mutex,0,1);
	int empty_sema=sem_init(&empty,0,MAX_QUEUE_SIZE);
	int full_sema=sem_init(&full,0,MAX_QUEUE_SIZE);
	if(sema<0||empty_sema<0||full_sema<0)
	{
		printf("Error in creating semaphore. Exitting..\n");
		exit(1);
	}
}

int left(int i)
{
	return 2*i+1;
}

int right(int i)
{
	return 2*i+2;
}

int parent(int i)
{
	return (i-1)/2;
}

void swap(job* j1,job* j2)
{
	job temp=*j1;
	*j1=*j2;
	*j2=temp;
}

void heapify(int i)
{
	int l=left(i);
	int r=right(i);
	int m=i;
	if(l<size&&priority_queue[l].priority>priority_queue[m].priority)
		m=l;
	if(r<size&&priority_queue[r].priority>priority_queue[m].priority)
		m=r;
	if(m!=i)
	{
		swap(&priority_queue[m],&priority_queue[i]);
		heapify(m);
	}
}

job create_job(int prod_no,pthread_t prod_tid,unsigned int *seed)
{
	job j;
	j.prod_no    =prod_no;
	j.prod_tid   =prod_tid;
	j.priority   =rand_r(seed)%MAX_PRIORITY+1;
	j.job_id     =rand_r(seed)%MAX_JOB_ID+1;
	j.comp_time  =rand_r(seed)%4+1;
	return j;  
}

void insert_job(job j)
{
	if(size==MAX_QUEUE_SIZE)
	{
		printf("Overflow. Exitting..\n");
		return;
	}
	priority_queue[size]=j;
	int i=size;
	size++;
	while(i!=0&&priority_queue[parent(i)].priority<priority_queue[i].priority)
	{
		swap(&priority_queue[i],&priority_queue[parent(i)]);
		i=parent(i);
	}
}

job remove_job()
{
	if(size==0)
	{
		job j;
		j.priority=-1;
		return j;
	}
	job j=priority_queue[0];
	priority_queue[0]=priority_queue[size-1];
	size--;
	heapify(0);
	return j;
}

void print_job(job j)
{
	printf("Job ID: %d,",j.job_id);
	printf("producer: %d,",j.prod_no);
	printf("producer tid: %lu,",j.prod_tid);
	printf("priority: %d,",j.priority);
	printf("compute time: %d\n",j.comp_time);
}