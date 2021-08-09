#include<limits.h>
#include<stdbool.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<fcntl.h>
#include<sys/select.h>
#include<signal.h>

#include "chat.h"

char server_ip[16];
uint16_t server_port;
int serv_sockfd;
struct sockaddr_in serv_addr;
struct user_info user_info;

int max(int a,int b)
{
	if(a>=b)
		return a;
	return b;
}

time_t min_time(time_t a,time_t b)
{
	if(a<=b)
		return a;
	return b;
}

void sig_handler(int signo)
{
	if(signo==SIGINT)
	{
		printf("\nClosing connection and ending process..\n");
		close(serv_sockfd);
		exit(0);
	}
}

void print_user_info(void)
{
	for(int i=0;i<user_info.num_peers;i++)
	{
		printf("Peer %d\n\tName: %s\n\tIP: %s\n\tPort: %d\n\n",
			i+1,user_info.table[i].username,user_info.table[i].ip,user_info.table[i].port);
	}
}

void start_server()
{
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(server_port);
	inet_pton(AF_INET,server_ip,&(serv_addr.sin_addr));
	memset(serv_addr.sin_zero,'\0',sizeof(serv_addr.sin_zero));

	if((serv_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)
	{
		printf("Error in creating socket. Exitting..\n");
		exit(1);
	}
	int yes=1;
	if(setsockopt(serv_sockfd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&yes,sizeof(int))<0)
	{
		printf("Error in port. Closing connection..\n");
		exit(1);
	}
	if(bind(serv_sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("Error in binding socket to port. Exitting..\n");
		exit(1);
	}
	if(listen(serv_sockfd,MAX_PEERS)<0)
	{
		printf("Error in listening for connection. Exitting..\n");
		exit(1);
	}
	printf("Receving at port %d\n",server_port);
}

void add_fds(fd_set* set,int* maxfd,struct timeval* min_timeout)
{
	FD_ZERO(set);
	FD_SET(serv_sockfd,set);
	FD_SET(STDIN_FILENO,set);
	*maxfd=serv_sockfd;
	min_timeout->tv_sec=LONG_MAX;
	struct timeval current_time;
	gettimeofday(&current_time,NULL);
	for(int i=0;i<user_info.num_peers;i++)
	{
		struct user_entry* current=&(user_info.table[i]);
		if(current->cli_sockfd>0)
		{
			if(current->timeout.tv_sec<=current_time.tv_sec)
			{
				close(current->cli_sockfd);
				current->cli_sockfd=-1;
			}
			else
			{
				FD_SET(current->cli_sockfd,set);
				*maxfd=max(*maxfd,current->cli_sockfd);
				min_timeout->tv_sec=min_time(min_timeout->tv_sec,current->timeout.tv_sec);
			}
		}
	}
	min_timeout->tv_usec=0;
	*maxfd=*maxfd+1;
}

void accept_connection()
{
	struct sockaddr_in cli_addr;
	int clisize=sizeof(cli_addr);
	int new_sockfd=accept(serv_sockfd,(struct sockaddr*)&cli_addr,&clisize);
	if(new_sockfd<0)
	{
		printf("Error in accepting connection. Exitting..\n");
		exit(1);
	}
	int valid=0;
	for(int i=0;i<user_info.num_peers;i++)
	{
		struct user_entry* current=&(user_info.table[i]);
		if(cli_addr.sin_addr.s_addr==current->peer_addr.sin_addr.s_addr
		  && cli_addr.sin_port==current->peer_addr.sin_port)
		{
			current->cli_sockfd=new_sockfd;
			reset_timeout(&current->timeout);
			valid=1;
			break;
		}
	}
	if(!valid)
	{
		close(new_sockfd);
		printf("Unknown client attempted to connect, rejected\n");
	}
}

void read_stdinput(char* buf,char* user,char* msg)
{
	int read_size;
	int len=0;
	char c;
	while((c=getchar())!='\n'&&len<MAX_BUF)
	{
		buf[len++]=c;
	}
	if(len==MAX_BUF&&c!='\n')
	{
		printf("Message input was longer than %d chars, clipped\n",MAX_BUF);
		buf[len-1]='\n';
		while((c=getchar())!='\n');
	}
	else
		buf[len++]='\n';
	int i;
	for(i=0;i<len;i++)
	{
		if(buf[i]=='/')
			break;
		user[i]=buf[i];
	}
	user[i]='\0';
	int j=0;
	i++;
	for(;i<len;i++)
	{
		msg[j]=buf[i];
		j++;
	}
	msg[j]='\0';
}

int main()
{
	char filename[MAX_BUF];
	printf("*** Welcome to P2P chat application ***\n");
	int f=0;char c;
	while((c=getchar())!='\n')
		filename[f++]=c;
	filename[f]='\0';
	FILE* uinfofile=fopen(filename,"r");
	if(!uinfofile)
	{
		printf("invalid input file\n");
		exit(1);
	}
	fscanf(uinfofile,"%s",server_ip);
	fscanf(uinfofile,"%hu",&server_port);
	fscanf(uinfofile,"%d",&(user_info.num_peers));

	for(int i=0;i<user_info.num_peers;i++)
	{
		struct user_entry* current=&(user_info.table[i]);
		fscanf(uinfofile,"%s %s %hu",current->username,current->ip,&current->port);
		current->cli_sockfd=-1;
		current->peer_addr.sin_family=AF_INET;
		current->peer_addr.sin_port=htons(current->port);
		if((current->peer_addr.sin_addr.s_addr=inet_addr(current->ip))<0)
		{
			printf("Invalid IP address. Exitting..\n");
			exit(1);
		}
		memset(current->peer_addr.sin_zero,'\0',sizeof(current->peer_addr.sin_zero));
	}

	signal(SIGINT,sig_handler);
	print_user_info();

	start_server();

	fd_set readfds;
	int maxfd;
	struct timeval min_timeout;
	int ready;
	char buf[MAX_BUF+1];
	char msg[MAX_BUF];
	char user[MAX_BUF];
	int read_size,sent_size;
	while(1)
	{
		add_fds(&readfds,&maxfd,&min_timeout);
		ready=select(maxfd,&readfds,NULL,NULL,&min_timeout);
		if(ready<=0)
			continue;
		if(FD_ISSET(serv_sockfd,&readfds))
			accept_connection();
		else if(FD_ISSET(STDIN_FILENO,&readfds))
		{
			read_stdinput(buf,user,msg);
			send_message(user,msg);
		}
		else
			receive_messages(buf,&readfds);
	}
	return 0;
}