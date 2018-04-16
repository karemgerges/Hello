#include "environment.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

char cwd[512];
char history_path[512];
char log_path[512];
char path[50][100];
int numofpathes;
void setup_environment( void )
{
	// you should implement this function
	getcwd(cwd, sizeof(cwd));
    strcpy(history_path,cwd);
    strcpy(log_path,history_path);
    strcat(history_path,"/history.txt");
    strcat(log_path,"/log.txt");
    char PATH[512];
    strcpy(PATH,getenv("PATH"));
    char *z = strtok(PATH,":");
    while (z) {
        strcpy(path[numofpathes],z);
        numofpathes++;
        z = strtok(NULL, ":");
              }
}

