#include <stdio.h>
#include <stdlib.h>

int bitHash(char *str)
{
	int hash = 0;
	while (*str != 0)
	{
		hash = hash * 1.5 + (((int)(*str)) % 100 + 1);
		str ++;
	}
	return hash;
}