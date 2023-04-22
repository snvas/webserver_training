#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>

int main(){
	int serverSock = 0;

	struct sockaddr_in addr;
	serverSock = socket(AF_INET, SOCK_STREAM, 0);

	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_family = AF_INET;
	addr.sin_port = htons(5555);

	connect(serverSock, (struct sockaddr *)&addr, sizeof(addr));
	printf("Connected to server \n");
	char buffer[1024]={'h', 'e', 'l', 'l', 'o', '.'};
	write(serverSock, buffer, strlen(buffer));
	printf("Message sent! with buffer is %s in Client\n", buffer);

	close(serverSock);
	printf("Socket closed! \n");


}