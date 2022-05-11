#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <unistd.h>

#include <arpa/inet.h>

#include <sys/types.h>

#include <sys/socket.h>

#include <netinet/in.h>

#define BUFF_SIZE 1024

#define SERVER "127.0.0.1"

int main()

{

int sockfd;

struct sockaddr_in server_addr;

char buff[BUFF_SIZE+5];

sockfd = socket(PF_INET, SOCK_STREAM, 0);

if (sockfd < 0) {

printf("Error creating socket!

");

exit(1);

}

printf("Socket created..

");

memset(&server_addr, 0, sizeof(server_addr));

server_addr.sin_family = AF_INET;

server_addr.sin_port = htons(8888);

server_addr.sin_addr.s_addr = inet_addr(SERVER);

if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) < 0) {

printf("Error connecting to server!

");

exit(1);

}

printf("Connected to server..

");

while (1) {

memset(buff, 0, sizeof(buff));

printf("Enter your message(type 'quit' to exit): ");

gets(buff);

if (strcmp(buff, "quit") == 0)

break;

send(sockfd, buff, strlen(buff), 0);

memset(buff, 0, sizeof(buff));

recv(sockfd, buff, BUFF_SIZE, 0);

printf("From server: %s

", buff);

}

close(sockfd);

return 0;

}
