#include "variables.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

char var[50][100];
char val[50][100];
char *input_line[512];
int numofvar ;

void set_variable(const char* input )
{
//input here is the variable and its value Like : x=5 or export x=5
                char value[100];
                strcpy(value,input);
                if(value[strlen(value)-1]!='"'){
                    char *m = strtok(input, "=");
                    strcpy(var[numofvar],m);
                    for(int h = 0; h< (strlen(value)-strlen(var[numofvar]) -1);h++){
                        val[numofvar][h] = value[h+strlen(var[numofvar])+1];
                    }

                }else
                {
                char *m = strtok(input, "=");
                strcpy(var[numofvar],m);
                m = strtok(NULL, "\"");
                strcpy(val[numofvar],m);
                }
                numofvar++;
}


void   set_complexvariable(const char* input)
{
    //input is null in case of : x="some string"
    //input is export in case of " export x="some string"
    //input_line here is the whole line from the user
    if(input == NULL){
    char *m = strtok(input_line, "=");
    strcpy(var[numofvar],m);
    m = strtok(NULL, "\"");
    strcpy(val[numofvar],m);
    }else if(!strcmp(input,"export")){
    char *m = strtok(input_line, " ");
    m = strtok(NULL, "=");
    strcpy(var[numofvar],m);
    m = strtok(NULL, "\"");
    strcpy(val[numofvar],m);
    }
    numofvar++;
}

void print_all_variables( void )
{
	for(int i =0;i<numofvar;i++)
	{
	printf("the variable is %s and the value is %s",var[i],val[i]);
	}
}
