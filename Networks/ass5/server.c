#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

#define SERV_PORT 1200
#define MAX_CON 10
#define MAXLEN 1000

int main(){
	struct sockaddr_in serv_addr, cli_addr;
	int clisize= sizeof(cli_addr);

	int serv_sockfd;

	char filename[MAXLEN];
	char buf[MAXLEN];
	FILE* msgfile;

	if((serv_sockfd=socket(PF_INET,SOCK_DGRAM,0))<0)
	{
		printf("Error in creating socket. Exitting..\n");
		exit(1);
	}

	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port   = htons(SERV_PORT);
	serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	memset(serv_addr.sin_zero,'\0',sizeof(serv_addr.sin_zero));

	if(bind(serv_sockfd,(struct sockaddr*)&serv_addr,sizeof(serv_addr))<0)
	{
		printf("Error in binding socket to server port. Exitting..\n");
		exit(1);
	}

	printf("Receving at port %d..\n",SERV_PORT);

	recvfrom(serv_sockfd,filename,MAXLEN,0,(struct sockaddr*)&cli_addr,&clisize);
	printf("Request received. Opening file %s..\n",filename);

	msgfile=fopen(filename,"r");
	if(msgfile==NULL)
	{
		char fnotfound[]="FILE_NOT_FOUND";
		sendto(serv_sockfd,fnotfound,strlen(fnotfound)+1,0,(struct sockaddr*)&cli_addr,clisize);
		printf("The requested file was not found. Clsing connection..\n");
		close(serv_sockfd);
		return 0;
	}

	fscanf(msgfile,"%s",buf);
	if(strcmp(buf,"HELLO")!=0)
	{
		char wformat[]="WRONG_FILE_FORMAT";
		sendto(serv_sockfd,wformat,strlen(wformat)+1,0,(struct sockaddr*)&cli_addr,clisize);
		printf("Wrong file format. Closing connection..\n");
		close(serv_sockfd);
		return 0;
	}

	sendto(serv_sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&cli_addr,clisize);
	int wordcount=1;
	while(1)
	{
		if(recvfrom(serv_sockfd,buf,MAXLEN,0,(struct sockaddr*)&cli_addr,&clisize)<0)
		{
			printf("Error in receiving data. Exitting..\n");
			fclose(msgfile);
			close(serv_sockfd);
			exit(1);
		}

		char word[MAXLEN]="WORD_";
		int len=snprintf(NULL,0,"%d",wordcount);
		char* wnum=malloc(sizeof(char)*(len+1));
		snprintf(wnum,len+1,"%d",wordcount);
		strcat(word,wnum);

		if(strcmp(word,buf)!=0)
		{
			char wmismatch[]="INCORRECT_COMMAND";
			sendto(serv_sockfd,wmismatch,strlen(wmismatch)+1,0,(struct sockaddr*)&cli_addr,clisize);
			printf("Incorrect command. Closing connection..\n");
			fclose(msgfile);
			close(serv_sockfd);
			return 0;
		}

		if(fscanf(msgfile,"%s",buf)<1)
		{
			char ueof[MAXLEN]="UNEXPECTED EOF";
			sendto(serv_sockfd,ueof,strlen(ueof)+1,0,(struct sockaddr*)&cli_addr,clisize);
			printf("Unexpected end of file. Closing connection..\n");
			fclose(msgfile);
			close(serv_sockfd);
			exit(1);
		}
		else
		{
			sendto(serv_sockfd,buf,strlen(buf)+1,0,(struct sockaddr*)&cli_addr,clisize);
			if(strcmp(buf,"END")==0)
				break;
		}
		wordcount++;
	}
	printf("Process completed. Closing connection..\n");
	fclose(msgfile);
	close(serv_sockfd);
	return 0;
}