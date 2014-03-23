#include <stdio.h>
#include <stdlib.h>
#include "../support/hash.c"
#include "node.c"

int main(int argc, char **argv)
{
	//printf("%d", bitHash("asd"));
	char *test; 
	popStr(&test, "iQueue");
	printf(test);
	
	//inputLog("apples are awesome");
	//sysLog("apples are awesome");
	return 0;
}
