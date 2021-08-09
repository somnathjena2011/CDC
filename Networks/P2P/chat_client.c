#include "chat.h"

extern int server_port;
extern struct sockaddr_in serv_addr;
extern struct user_info user_info;

void reset_timeout(struct timeval* timeout)
{
	gettimeofday(timeout,NULL);
	timeout->tv_sec+=TIMEOUT;
	timeout->tv_usec=0;
}

void send_message(char* user,char* msg)
{
	int user_exists=0;
	int sent_size,len;
	for(int i=0;i<user_info.num_peers;i++)
	{
		struct user_entry* current=&(user_info.table[i]);
		if(strcmp(user,current->username)==0)
		{
			user_exists=1;
			if(current->cli_sockfd<0)
			{
				if((current->cli_sockfd=socket(PF_INET,SOCK_STREAM,0))<0)
				{
					printf("Error in creating client socket. Exitting..\n");
					exit(1);
				}
				int yes=1;
				if(setsockopt(current->cli_sockfd,SOL_SOCKET,SO_REUSEADDR|SO_REUSEPORT,&yes,sizeof(int))<0)
				{
					printf("Error in port. Closing connection..\n");
					exit(1);
				}
			}
			if(bind(current->cli_sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
			{
				printf("Unable to bind to server port. Exitting..\n");
				exit(1);
			}
			if(connect(current->cli_sockfd,(struct sockaddr*)&current->peer_addr,sizeof(current->peer_addr))<0)
			{
				if(errno==ECONNREFUSED)
				{
					printf("The connection could not be made. The client may not be online.\n");
					close(current->cli_sockfd);
					current->cli_sockfd=-1;
					break;
				}
				else
				{
					printf("The connection could not be made. Exitting..\n");
					close(current->cli_sockfd);
					exit(1);
				}
			}
			len=strlen(msg);
			sent_size=0;
			while(sent_size!=len)
				sent_size+=send(current->cli_sockfd,msg+sent_size,len-sent_size,0);
			reset_timeout(&current->timeout);
			break;
		}
	}
	if(!user_exists)
		printf("The username does not correspond to a peer.\n");
}

void receive_messages(char* buf,fd_set* set)
{
	int read_size;
	for(int i=0;i<user_info.num_peers;i++)
	{
		struct user_entry* current=&(user_info.table[i]);
		if(current->cli_sockfd>0&&FD_ISSET(current->cli_sockfd,set))
		{
			int firstbuf = 1;
			while((read_size=recv(current->cli_sockfd,buf,MAX_BUF,0))>0)
			{
				if(firstbuf)
				{
					printf("%s: ",current->username);
					firstbuf=0;
				}
				buf[read_size]='\0';
				printf("%s",buf);
				if(buf[read_size-1]=='\n')
					break;
			}
			if(read_size==0)
			{
				close(current->cli_sockfd);
				current->cli_sockfd=-1;
			}
			else
			{
				reset_timeout(&current->timeout);
			}
		}
	}
}