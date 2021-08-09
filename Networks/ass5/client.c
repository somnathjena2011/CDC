#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<fcntl.h>
#include<netdb.h>

#define SERV_PORT 1200
#define MAXLEN 1000

int main(){
	struct sockaddr_in serv_addr;
	int serv_size= sizeof(serv_addr);

	int cli_sockfd;
	int recvfd;
	int numbytes;

	char filename[MAXLEN];
	char buf[MAXLEN];
	char msg[MAXLEN];

	if((cli_sockfd=socket(PF_INET,SOCK_DGRAM,0))<0)
	{
		printf("Error in creating socket. Exitting..\n");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = ntohs(SERV_PORT);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serv_addr.sin_zero,'\0',sizeof(serv_addr.sin_zero));

	printf("Enter filename\n");
	scanf("%s",filename);

	if((numbytes=sendto(cli_sockfd,filename,strlen(filename)+1,0,(struct sockaddr*)&serv_addr,serv_size))<0)
	{
		printf("Error in sending filename. Exitting..\n");
		close(cli_sockfd);
		exit(1);
	}
	printf("Request sent to server\n");

	if((numbytes=recvfrom(cli_sockfd,buf,MAXLEN,0,(struct sockaddr*)&serv_addr,&serv_size))<0)
	{
		printf("Error in receving response. Exitting..\n");
		close(cli_sockfd);
		exit(1);
	}
	printf("Response received\n");
	if(strcmp(buf,"FILE_NOT_FOUND")==0)
	{
		printf("File Not Found\n");
		close(cli_sockfd);
		return 0;
	}
	else if(strcmp(buf,"WRONG_FILE_FORMAT")==0)
	{
		printf("Wrong file format\n");
		close(cli_sockfd);
		return 0;
	}
	else if(strcmp(buf,"HELLO")==0)
	{
		printf("Creating local file..\n");
		recvfd=open("received.txt",O_CREAT|O_TRUNC|O_WRONLY,0666);
		if(recvfd<0)
		{
			printf("Error in creating file. Exitting..\n");
			close(cli_sockfd);
			exit(1);
		}
		int wordcount=1;
		sprintf(msg,"WORD_%d",wordcount);
		numbytes=sendto(cli_sockfd,msg,strlen(msg)+1,0,(struct sockaddr*)&serv_addr,serv_size);
		do{
			numbytes=recvfrom(cli_sockfd,buf,MAXLEN,0,(struct sockaddr*)&serv_addr,&serv_size);
			if(strcmp(buf,"END")==0)
			{
				printf("Closing file..\n");
				close(recvfd);
				printf("Closing connection..\n");
				close(cli_sockfd);
				return 0;
			}
			strcat(buf,"\n");
			write(recvfd,buf,strlen(buf));
			wordcount++;
			sprintf(msg,"WORD_%d",wordcount);
			numbytes=sendto(cli_sockfd,msg,strlen(msg)+1,0,(struct sockaddr*)&serv_addr,serv_size);
		}while(1);
	}
	else
	{
		printf("No data received. Closing connection..\n");
		close(cli_sockfd);
	}
	return 0;
}