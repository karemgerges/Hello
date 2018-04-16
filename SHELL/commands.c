#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "commands.h"

char inputline[512];
char history_path[512] ;
char *get_user_name()
{
    char *username = getenv("USER");
    return username;
}

char *get_user_path()
{
    char *username = getenv("USER");
    char newpath[100] = "/home/";
    strcat(newpath,username);
    char *userpath = newpath;
    return userpath;
}

void cd( const char* path )
{
	//check if change directory
    char check[200];
    if(path == NULL){
        char *user_path = get_user_path();
        chdir(user_path);
    }else{
        strcpy(check,path);                          //put the path in the string check
        if(check[0]=='~' && strlen(check) == 1){      //if the command is cd ~   then iw will go to /home/username
            char *user_path = get_user_path();
            chdir(user_path);
        }else if(check[0]=='~'){
            char *input_user_name = strtok(path,"~");           //the user name entered after ~  ==> ~USERNAME
            if(!strcmp(input_user_name,get_user_name())){
                char *user_path = get_user_path();
                chdir(user_path);
            }else{
            printf("%s: No such file or directory\n",input_user_name);
            }
        }else{
            int d = chdir(path);
            if(d == -1)
                printf("%s: No such file or directory\n",path);
             }
        }
}


void ECHO( const char* message )
{
	// you should implement this function
	if(message==NULL){          //ECHO THEN EMPTY LINE
        printf("\n");
	}else{
        char print[256];
        strcpy(print,message);
        if(print[0] == '"'){
            char *tobeprinted = strtok(inputline, "\"");
            tobeprinted = strtok(NULL, "\"");
            printf("%s\n",tobeprinted);
        }else{
            char *tobeprinted = strtok(inputline, " ");
            tobeprinted = strtok(NULL, " ");
            while(tobeprinted){
            printf("%s ",tobeprinted);
            tobeprinted = strtok(NULL, " ");
            }
            printf("\n");
        }
    }
}

