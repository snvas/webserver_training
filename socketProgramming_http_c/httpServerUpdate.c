#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(){
	int server = 0, client = 0;
	struct sockaddr_in serverAddr;

	char message[9999];
	//HTTP/1.1 200 OK → This mentions what version of HTTP we are using, Status code and Status message.
	//Content-Type: text/html → This says that I’m (server) sending a html.
	//Content-Length: 47 → It mentions how many bytes the server is sending to the client. The web-browser only reads how much we mention here.
	strcpy(message, "HTTP/1.1 200 OK\nContent-length: 47\nContent-Type: text/html\n\n<html><body><h1>Learning Socket Programmig</h1></body></html>");

	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(8080);

	bind(server, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
	listen(server, 0);

	printf("Listening for incoming connections...\n");

	char buffer[1024];
	int msg_len;

	client = accept(server, (struct sockaddr *)NULL, NULL);
	printf("Client connected! \n");
	read(client, buffer, sizeof(buffer)-1);

	printf("client says: buffer is %s \n", buffer);
	memset(buffer, 0, sizeof(buffer));
	msg_len = write(client, message, strlen(message));
	if (msg_len == 0){
		printf("Client disconnected! \n");
		close(client);
		return -1;
	}


}