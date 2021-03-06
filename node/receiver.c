#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <netdb.h>
#include <stdio.h>
#include "node.c"

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

/*
open up port Pi
*/
int main(int argc, char *argv[])
{
	int sock, length, n;
	socklen_t fromlen;
	struct sockaddr_in server;
	struct sockaddr_in from;
	char *buf = (char *) calloc(100, sizeof(char));
	argv[1] = "31415";

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) 
		error("Opening socket");
	length = sizeof(server);
	bzero(&server, length);
	server.sin_family=AF_INET;
	server.sin_addr.s_addr=INADDR_ANY;
	server.sin_port=htons(atoi(argv[1]));
	if (bind(sock, (struct sockaddr *)&server, length) < 0) 
		error("binding");
	fromlen = sizeof(struct sockaddr_in);
	while (1) 
	{
		n = recvfrom(sock,buf,100,0,(struct sockaddr *)&from,&fromlen);
		if (n < 0)
			error("recvfrom");
		sysLog("Received a datagram\n");
		inputLog(buf);
		sysLog("written\n");
        free(buf);
        buf = (char *) calloc(100, sizeof(char));
	}
	return 0;
}