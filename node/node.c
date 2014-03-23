#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sysLog (char *message)
{
	printf(message);
	writeStr(message, "systemLog");
	return;
}

void inputLog (char *message)
{
	writeStr(message, "iQueue");
	return;
}

void outputLog (char *message)
{
	writeStr(message, "oQueue");
	return;
}


//writes line at end of file
void writeStr (char *message, char *file)
{	
	char str[80] = "../database/", line[60];
	strcat (str, file);

	FILE *fp, *ftemp;
	fp= fopen(str, "r");
	ftemp = fopen("../database/temp", "w");

	if(fp == NULL || ftemp == NULL)
    {
    	printf("the file to write in doesn't exist!!!\n");
    	return;
    }

    while(fgets(line, 60, fp) != NULL)
    {
        fprintf(ftemp, line);
    }

	fprintf(ftemp, message);
	fprintf(ftemp, "\n");

	fclose(fp);
	fclose(ftemp);
	rename("../database/temp", "../database/temp1" );
	rename(str, "../database/temp" );
	rename("../database/temp1", str);
	return;
}

//gets first line of file
void popStr (char **storage, char *file)
{
	int count = 0;
	char str[80] = "../database/", line[60];
	strcat (str, file);

	FILE *fp, *ftemp;
	fp= fopen(str, "r");
	ftemp = fopen("../database/temp", "w");

	if(fp == NULL || ftemp == NULL)
    {
    	printf("the file to write in doesn't exist!!!\n");
    	return;
    }

    while(fgets(line, 60, fp) != NULL)
    {
    	if (count == 0)
    	{
    		*storage = line;
    	}else
    	{
    		fprintf(ftemp, line);
    	}
        count += 1;
    }

	fclose(fp);
	fclose(ftemp);
	rename("../database/temp", "../database/temp1" );
	rename(str, "../database/temp" );
	rename("../database/temp1", str);
	return;
}
