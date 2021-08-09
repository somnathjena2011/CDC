#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<unistd.h>
#include<sys/shm.h>
#include<sys/ipc.h>
#include<time.h>
#include<signal.h>
#include<errno.h>

#define MAX_QUEUE_SIZE 8
#define MAX_PRIORITY 10
#define MAX_JOB_ID 100000

typedef struct job{
	pid_t prod_pid;
	int prod_no;
	int prod_priority;
	int comp_time;
	int job_id;
} job;

typedef struct shared_memory{
	job priority_queue[MAX_QUEUE_SIZE];
	int size;
	int job_created;
	int job_completed;
	int max_jobs;
	int computed;
	sem_t mutex;
	sem_t full;
	sem_t empty;
} shared_memory;

shared_memory* init_shm(int shmid,int max_jobs);
job create_job(pid_t prod_pid,int prod_no);
void print_job(job j);

void producer(int shmid,int prod_no,pid_t prod_pid);
void consumer(int shmid,int cons_no,pid_t cons_pid);

int left(int i);
int right(int i);
int parent(int i);
void swap(job* j1,job* j2);
void heapify(shared_memory* shm,int i);
void insert_job(shared_memory* shm,job j);
job remove_job(shared_memory* shm);

int main()
{
	srand(time(0));
	int NP,NC,max_jobs;
	scanf("%d %d %d",&NP,&NC,&max_jobs);

	pid_t prods[NP];
	pid_t conss[NC];

	key_t key=ftok("/dev/random",'c');
	int shmid=shmget(key,sizeof(shared_memory),0666|IPC_CREAT);
	if(shmid<0)
	{
		printf("Error in created shared memory. Exitting..\n");
		exit(1);
	}

	shared_memory* shm=init_shm(shmid,max_jobs);

	time_t start = time(0);

	pid_t pid;
	for(int i=1;i<=NP;i++)
	{
		pid=fork();
		if(pid<0)
		{
			printf("Error in forking. Exitting..\n");
			exit(1);
		}
		else if(pid==0)
		{
			srand(time(0)+i);
			int prod_pid=getpid();
			producer(shmid,i,prod_pid);
			return 0;
		}
		else
			prods[i-1]=pid;
	}

	for(int i=1;i<=NC;i++)
	{
		pid=fork();
		if(pid<0)
		{
			printf("Error in forking. Exitting..\n");
			exit(1);
		}
		else if(pid==0)
		{
			srand(time(0)+NP+i);
			int cons_pid=getpid();
			consumer(shmid,i,cons_pid);
			return 0;
		}
		else
			conss[i-1]=pid;
	}

	while(1)
	{
		sem_wait(&(shm->mutex));
		if(shm->job_created==max_jobs && shm->job_completed==max_jobs)
		{
			time_t end=time(0);
			int time_taken = end-start;
			printf("Total time taken to run %d jobs = %d seconds\n",max_jobs,time_taken);
			for(int i=0;i<NP;i++)
				kill(prods[i],SIGTERM);
			for(int i=0;i<NC;i++)
				kill(conss[i],SIGTERM);
			sem_post(&(shm->mutex));
			break;
		}
		sem_post(&(shm->mutex));
	}
	sem_destroy(&(shm->mutex));
	shmdt(shm);
	shmctl(shmid,IPC_RMID,0);
	return 0;
}

void producer(int shmid,int prod_no,pid_t prod_pid)
{
	shared_memory* shm=shmat(shmid,NULL,0);
	while(1)
	{
		if(shm->job_created==shm->max_jobs)
			break;
		job j=create_job(prod_pid,prod_no);
		sleep(rand()%4);
		sem_wait(&(shm->empty));
		sem_wait(&(shm->mutex));
		if(shm->job_created==shm->max_jobs)
		{
			sem_post(&(shm->mutex));
			break;
		}
		if(shm->size < MAX_QUEUE_SIZE)
		{
			insert_job(shm,j);
			printf("Produced jobs details\n");
			print_job(j);
			shm->job_created++;
			sem_post(&(shm->full));
		}
		sem_post(&(shm->mutex));
	}
	shmdt(shm);
}

void consumer(int shmid,int cons_no,pid_t cons_pid)
{
	shared_memory* shm=(shared_memory*)shmat(shmid,NULL,0);
	while(1)
	{
		if(shm->job_completed==shm->max_jobs)
			break;
		sleep(rand()%4);
		sem_wait(&(shm->full));
		sem_wait(&(shm->mutex));
		job j;int job_retrieved=0;
		if(shm->job_completed==shm->max_jobs)
		{
			sem_post(&(shm->mutex));
			break;
		}
		if(shm->size>0)
		{
			j=remove_job(shm);
			job_retrieved=1;
		}
		sem_post(&(shm->mutex));
		if(job_retrieved)
		{
			printf("Consumed job details\n");
			printf("consumer: %d,",cons_no);
			printf("consumer pid: %d,",cons_pid);
			print_job(j);
			sem_wait(&(shm->mutex));
			shm->job_completed++;
			sem_post(&(shm->mutex));
			sem_post(&(shm->empty));
			sleep(j.comp_time);
		}
	}
	shmdt(shm);
}

shared_memory* init_shm(int shmid,int max_jobs)
{
	shared_memory* shm=(shared_memory*)shmat(shmid,NULL,0);
	shm->size = 0;
	shm->max_jobs = max_jobs;
	shm->job_created = 0;
	shm->job_completed = 0;
	shm->computed = 0;

	int sema=sem_init(&(shm->mutex),1,1);
	int full_sema=sem_init(&(shm->full),1,0);
	int empty_sema=sem_init(&(shm->empty),1,MAX_QUEUE_SIZE);

	if(sema<0||full_sema<0||empty_sema<0)
	{
		printf("Error in initializing semaphore. Exitting..\n");
		exit(1);
	}
	return shm;
}

job create_job(pid_t prod_pid,int prod_no)
{
	job j;
	j.prod_pid     =prod_pid;
	j.prod_no      =prod_no;
	j.prod_priority=rand()%MAX_PRIORITY+1;
	j.comp_time    =rand()%4+1;
	j.job_id       =rand()%MAX_JOB_ID+1;
	return j;
}

void print_job(job j)
{
	printf("Job ID: %d,",j.job_id);
	printf("producer: %d,",j.prod_no);
	printf("producer pid: %d,",j.prod_pid);
	printf("priority: %d,",j.prod_priority);
	printf("compute time: %d\n",j.comp_time);
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

void heapify(shared_memory* shm,int i)
{
	int l=left(i);
	int r=right(i);
	int m=i;
	if(l<shm->size && shm->priority_queue[l].prod_priority>shm->priority_queue[m].prod_priority)
		m=l;
	if(r<shm->size && shm->priority_queue[r].prod_priority>shm->priority_queue[m].prod_priority)
		m=r;
	if(m!=i)
	{
		swap(&(shm->priority_queue[i]),&(shm->priority_queue[m]));
		heapify(shm,m);
	}
}

void insert_job(shared_memory* shm,job j)
{
	if(shm->size==MAX_QUEUE_SIZE)
	{
		printf("Overflow: Cannot insert\n");
		return;
	}
	shm->size++;
	int i=shm->size-1;
	shm->priority_queue[i]=j;
	while(i!=0 && 
	shm->priority_queue[parent(i)].prod_priority<shm->priority_queue[i].prod_priority)
	{
		swap(&(shm->priority_queue[i]),&(shm->priority_queue[parent(i)]));
		i=parent(i);
	}
}

job remove_job(shared_memory* shm)
{
	if(shm->size==0)
	{
		job j;
		j.prod_priority=-1;
		return j;
	}
	job root=shm->priority_queue[0];
	shm->priority_queue[0]=shm->priority_queue[shm->size-1];
	shm->size--;
	heapify(shm,0);
	return root;
}