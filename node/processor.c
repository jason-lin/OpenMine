#include <stdio.h>
#include <stdlib.h>
#include "../support/hash.c"
#include "node.c"


void check()
{
	int length;
	int count;
	char subbuff[128];
	char *block = "hxor", *currblock = (char *) malloc(1024 * sizeof(char));

	popStr(&block, "iQueue");
	//does nothing if nothing is in iQueue
	if ((block[0] == 'h')&& (block[1] == 'x')&&(block[2] == 'o')&&(block[3] == 'r'))
	{
		return;
	}

	strcpy(currblock, block);
	sysLog("received new block:\n");
	printf(currblock);

	length = strlen(currblock);
	//already broken block
	if (length < 128)
	{
		sysLog("processing block\n");
		sleep(3); //this is used to act like a fake processing thing
		outputLog(currblock);
	}
	//huge block; needs breaking
	else
	{
		sysLog("block too big; distributing block\n");
		count = 0;
		while (count < length)
		{
			memcpy(subbuff, &currblock[count], 112);
			subbuff[113] = '\0';

			if(count + 112 < length) //sends out every block except for the last one
			{
				outputLog(subbuff);
			}
			count += 112;
		}
		//process the last block
		sysLog("processing block\n");
		sleep(3);
		outputLog(subbuff);
	}
}


int main(int argc, char **argv)
{

	while(1)
	{
		check();
	}
	//printf("%d", bitHash("asd"));
	//inputLog("apples are awesome");
	//sysLog("apples are awesome");
	return 0;
}