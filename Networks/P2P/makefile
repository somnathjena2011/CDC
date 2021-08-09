chatApp: chat_server.o chat_client.o
	gcc chat_server.o chat_client.o -o chatApp

chat_client.o: chat_client.c chat.h
	gcc -c chat_client.c

chat_server.o: chat_server.c chat.h
	gcc -c chat_server.c

clean:
	rm chat_client.o chat_server.o chatApp