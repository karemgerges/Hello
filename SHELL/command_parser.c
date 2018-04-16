#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "command_parser.h"
//char arg[100][50];
int numofvar;    //num of variables that the user declared i the arrays
char var[50][100];
char val[50][100];
int var_length;
int indexofdollarsign;
char variable[50];
char value[256];
int valueIndex ;
char inputline[512];

void parse_variable(char* str)
{

    int numofvarinline = 0;        //number of variables in the string
    inputline[512]="";
    strcpy(inputline,str);

    //this loop to count number of variables in the command
    for(int i =0; i<strlen(inputline);i++)
    {
        if(inputline[i]=='$'){
            numofvarinline++;
            }
    }


    for(int j=0;j<numofvarinline;j++)
    {
    var_length = 0;
    indexofdollarsign;
    variable[50]= "";
    value[256]= "";
    valueIndex ;      //index of value of the variable

        for(int h=0;h < strlen(inputline);h++)
        {

            if(inputline[h]=='$')
            {
            indexofdollarsign = h;
            h++;
                while(isalnum(inputline[h]))
                {
                variable[var_length] = inputline[h];
                var_length++;
                h++;
                }
                if(inputline[h]=='\\'){
                var_length++;
                }
                //search in the array of variables
                valueIndex = search_for_variable(variable);
                if(valueIndex == -1)
                {
                    //variable is not found in the array
                    //then search in the environment variable
                    if(getenv(variable) != NULL){
                    strcpy(value,getenv(variable));
                    }
                }else{
                    //variable is  found in the array
                    strcpy(value,val[valueIndex]);
                }
                    shiftAndReplace();
                    h = strlen(inputline);    //to break from the loop
            }
        }
    }
    strcpy(str,inputline);
}

void shiftAndReplace()
{

    char tobemodified[512];
    strcpy(tobemodified,inputline);

    int difference = strlen(value) - (var_length + 1);
    //shifting
    if(difference > 0){
        for(int i = strlen(tobemodified)-1;i>=indexofdollarsign;i--)
        {
            tobemodified[i+difference] = tobemodified[i];
        }
    }else if(difference < 0){
        for(int i = indexofdollarsign;i<strlen(tobemodified);i++)
        {
            tobemodified[i] = tobemodified[i-difference];
        }
    }

    //replacing
    for(int j = 0; j<strlen(value);j++)
    {
    tobemodified[indexofdollarsign+j] = value[j];
    }
    strcpy(inputline,tobemodified);
}


int search_for_variable(char* variable)
{
        //this function search for the varable in the arraya
        //and returns the index if found else return -1
            for(int f=0;f<numofvar;f++){
                        if(!strcmp(variable,var[f])){
                        return f;
                        }
                    }
                    return -1;
}

