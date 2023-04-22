#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(){
	int server = 0, client = 0;
	struct sockaddr_in serverAddr;
	server = socket(AF_INET, SOCK_STREAM, 0);

	serverAddr.sin_addr.s_addr = INADDR_ANY;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(5555);

	bind(server, (struct sockaddr *)&serverAddr, sizeof(serverAddr));
	listen(server, 0);

	printf("Listening for incoming connections...\n");

	char buffer[1024];

	client = accept(server, (struct sockaddr *)NULL, NULL);
	printf("Client connected! \n");
	read(client, buffer, sizeof(buffer)-1);

	printf("client says: buffer is %s \n", buffer);
	memset(buffer, 0, sizeof(buffer));
	close(client);
	printf("Client disconnected! \n");


}