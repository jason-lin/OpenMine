#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sysLog (char *message)
{
	writeStr(message, "systemLog");
}

void inputLog (char *message)
{
	writeStr(message, "iQueue");
}

void outputLog (char *message)
{
	writeStr(message, "oQueue");
}

void writeStr (char *message, char *file)
{	
	char *dir = "../database/";
	char str[80], line[60];
	strcat (str, dir);
	strcat (str, file);

	FILE *fp, *ftemp;
	fp=fopen(str, "r");
	ftemp = fopen("../database/temp", "w");
	if(fp == NULL || ftemp == NULL)
    	return;

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
}