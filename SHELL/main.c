#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "variables.h"
#include <signal.h>
#include "environment.h"
#include "command_parser.h"
#include "file_processing.h"
#include "commands.h"

typedef enum{ false = 0 , true = 1 } bool ;
void start(bool read_from_file);
void shell_loop(bool input_from_file);
char filepath[100];
FILE* file ;
FILE* HISTORY ;
FILE* log_file ;
char history_path[512] ;
char log_path[512];
char *input_line[512];
char var[50][100];
char val[50][100];
char path[50][100];
int numofpathes = 0;
int numofvar = 0;
char input[512];
char *str = input ;

int main(int argc, char *argv[])
{
    setup_environment();
    // any other early configuration should be here

    if( argc > 1 ){
        strcpy(filepath,argv[1]);
        start(true);
    }
    else{
        start(false);
    }

    return 0;
}

void start(bool read_from_file)
{
    //get current working Directory before changed to use it in files pathes

	//cd(""); // let shell starts from home
    chdir("/home");

    if(read_from_file){
		// file processing functions should be called from here
        file = fopen(filepath, "r");
        if(file){
		shell_loop(true);
        }else{
        printf("file doesn't exists or cannot be opened\n");
        }
	}
	else{
		shell_loop(false);
	}
}


void write_to_log()
{
    pid_t pid;
    pid = wait(NULL);
    log_file = fopen(log_path, "a");
    fprintf(log_file, "child process was terminated  : Pid %d \n", pid);
    fclose(log_file);
}

int check_background(){
        for(int i = strlen(str) -1;i >=0; i-- )
        {
            if(str[i]=='&')
            {
            str[i] = ' ';
            return 1;
            }
            if(str[i]!=' ')
            {
            return 0;
            }
        }
}

void shell_loop(bool input_from_file)
{
    int backflag;     //if set to 1 then the operation will run in the background
	bool from_file = input_from_file;
	while(true){
	 signal(SIGCHLD, write_to_log);
		if(from_file){
			//read next incommanduction from file
            char line[256] = "";
            char modified[256]="" ;
            if(fgets(line, sizeof(line), file)){
            for(int i =0;i < strlen(line)-1;i++){
            modified[i] = line[i];
            }
            strcpy(str,modified);
            if(strlen(str)==0){
                continue;
            }
            }else{
                fclose(file);
                break;
            }
            printf("%s",line);
            }
		else{
            //read next incommanduction from console
            printf("shell >");
            gets(str);
		}
		if(feof(stdin)){
		printf("\n");
		break;
		}
		//check whether the command will run in the bacj=kgroun or foreground
		//backflag == 1 ===> Command will run in the background
        backflag = check_background();
        // if the command contain variables this function replaces it by its value
		parse_variable(str);

        //check that the input length is less than 512
        if( strlen(str) < 512){

        //parsing the command
        pid_t  pid;
        char *echo[512];
        strcpy(echo,str);
        strcpy(input_line,str);
        char **parts = NULL;
        char *p = strtok(str, " ");
        int partNum = 0;
        while (p) {
            parts = realloc(parts, sizeof(char *) * ++partNum);
            if (parts == NULL)
                exit(-1); /* memory allocation failed */
            parts[partNum - 1] = p;
            p = strtok(NULL, " ");
                  }
        parts = realloc(parts, sizeof(char *) * (partNum + 1));
        parts[partNum] = 0;

        if(partNum!=0){                 //zero in case of empty line
        //write line to history
        HISTORY = fopen(history_path, "a");
        fprintf(HISTORY,"%s\n",input_line);
        fclose(HISTORY);
        //if the input line is not empty it will continue
        char firstword[100] ;
        strcpy(firstword,parts[0]);

        //check for variables
        int varflag = 0;
        for(int k =0 ;k < strlen(firstword);k++){
            if(firstword[k]=='='){
                varflag = 1;
            }
        }
        //checking if the command is a comment or not
        if(firstword[0]!='#')
        {
            if(!strcmp(firstword, "exit")){
                    break;
            }else if(!strcmp(parts[0], "cd")){
                cd(parts[1]);
            }else if(varflag){
                if(parts[1]==NULL)
                    set_variable(parts[0]);
                else
                    set_complexvariable(NULL);
            }else if(!strcmp(firstword, "export")){
                if(parts[2]==NULL)
                    set_variable(parts[1]);
                else
                    set_complexvariable("export");
            }else if(!strcmp(firstword, "echo")){
                ECHO(parts[1]);
            }else{
                pid = fork();
    //            printf("fork sucsseded\n");
                if (pid == 0)
                {
                //child process goes here
                    if(!strcmp(firstword, "history")){
                        char *const parmList[] = {"/bin/cat",history_path,NULL};
                        execv("/bin/cat",parmList);
                        }
                    //check if first character is / or not "path is given " or search in the $PATH will happen
                    if(firstword[0] == '/')
                    {
                        execv(parts[0], parts);
                        printf("%s : command not found\n",parts[0]);
                    }else{
                        for(int j=0;j<numofpathes;j++){
                        char PATH[512];
                        strcpy(PATH,path[j]);
                        strcat(PATH,"/");
                        strcat(PATH,firstword);
                        char *pointer = PATH;
                        parts[0] = pointer;
                        execv(parts[0], parts);
                    }
                        printf("%s : command not found\n",firstword);

                        }
                    exit(0);
                }
                else
                {
                //parent process goes HERE
                //if process in background ==> parent don't wait for process termination
                //else if process in foreground ==> parent wait for process termination
                    if(backflag == 0){
                            while (wait(NULL) != -1) {
                                // nothing
                                    }
                        }
                    }
                }
            }
	}
	}else{
        printf("strerr\n string legth has exceed the limit");
	}
	}

	}
