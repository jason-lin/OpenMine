#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include "node.c"

//./sender 127.0.0.1 100000 asdgasdgasdgasdg

void sender()
{
	int s;
	int ret;
	struct sockaddr_in addr;

	char *ip_temp, *ip = (char *) malloc(20 * sizeof(char));
	char *port = "31415"; //pi port so coollllll!!
	char *buf_temp = "hxor", *buf = (char *) malloc(1024 * sizeof(char));


 	addr.sin_family = AF_INET;
	
 	//get the datagram
	popStr(&buf_temp, "oQueue");
	//does nothing if nothing is in oQueue
	if ((buf_temp[0] == 'h')&& (buf_temp[1] == 'x')&&(buf_temp[2] == 'o')&&(buf_temp[3] == 'r'))
	{
		printf("i am batman!\n");
		return;
	}
	strcpy(buf, buf_temp);
	sysLog("read an output block:\n");
	s = socket(PF_INET, SOCK_DGRAM, 0);
	if (s == -1) 
	{
		perror("socket"); exit(1); 
	}

 	//rotate the ip to send to in order to balance the system
 	popStr(&ip_temp, "all_nodes"); //pop first
 	//printf(ip_temp);
 	strcpy(ip, ip_temp);
 	ipLog(ip); //write to last

 	//now open the ip port
	ret = inet_aton(ip, &addr.sin_addr);
	if (ret == 0) 
	{ 
		perror("inet_aton"); exit(1); 
	}

	//sets the port
	addr.sin_port = htons(atoi(port));

	//finally sends it
 	ret = sendto(s, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
	if (ret == -1) 
	{ 
		perror("sendto"); exit(1); 
	}
}

int main(int argc, char **argv)
{
	while(1)
	{
		sender();
		sleep(1); //artificial constraint <-- erase once done
	}
	return 0;
}
