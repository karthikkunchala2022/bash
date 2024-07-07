#include <stdio.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>
#include<string.h>
#include<unistd.h>
#define MAX 1000
#include"cptrailheader.h"
#include"cpvheader.h"
#include"cpiheader.h"
#include"cplheader.h"
#include"cpfheader.h"
#include"mvheader.h"
#include"mvvheader.h"
#include"mviheader.h"
#include"mvlheader.h"
#include"mvfheader.h"
#include"lsheader.h"
#include"lsaheader.h"
#include"lsSheader.h"
#include"lssheader.h"
#include"lsUheader.h"
#include"grepheader.h"



int main() {
    char* input;
    char owner[100];
    char currentdirectory[1000];
    char* username;    
    while(1) {
    username = getlogin();
    gethostname(owner,100);
    getcwd(currentdirectory,1000);
    strcat(username,"@");
    strcat(username,owner);
    strcat(username,currentdirectory);
    strcat(username,"$");
    input=readline(username);
    
        
        
        if(strlen>0){
         add_history(input);
	
    char *space[100];
    char *token = strtok(input, " ");
    int i = 0;
    int j;
    char *argv[MAX];
    int argc;
    while (token != NULL){
    if(strcmp(input,"cp")==0){
    space[i] = argv[i];
    cp(argc,space[i]);
    }
    if(strcmp(input,"cp -v")==0){
    space[i] = argv[i];
    cpv(argc,space[i]);
    }
    if(strcmp(input,"cp -i")==0){
    space[i] = argv[i];
    cpi(argc,space[i]);
    }
    if(strcmp(input,"cp -l")==0){
    space[i] = argv[i];
    cpl(argc,space[i]);
    }
    if(strcmp(input,"cp -f")==0){
    space[i] = argv[i];
    cpf(argc,space[i]);
    }
   if(strcmp(input,"mv")==0){
    space[i] = argv[i];
    mv(argc,space[i]);
    }
    if(strcmp(input,"mv -v")==0){
    space[i] = argv[i];
    mvv(argc,space[i]);
    }
    if(strcmp(input,"mv -i")==0){
    space[i] = argv[i];
    mvi(argc,space[i]);
    }
    if(strcmp(input,"mv -l")==0){
    space[i] = argv[i];
    mvl(argc,space[i]);
    }
    if(strcmp(input,"mv -f")==0){
    space[i] = argv[i];
    mvf(argc,space[i]);
    }
    if(strcmp(input,"ls")==0){
    space[i] = argv[i];
    ls();
    }
    if(strcmp(input,"ls -a")==0){
    space[i] = argv[i];
    lsa();
    }
    if(strcmp(input,"ls -U")==0){
    space[i] = argv[i];
    lsU();
    }
    if(strcmp(input,"ls -s")==0){
    space[i] = argv[i];
    lss();
    }
    if(strcmp(input,"ls -S")==0){
    space[i] = argv[i];
    lsS();
    }
    if(strcmp(input,"grep")==0){
    space[i] = argv[i];
    grep(argc,space[i]);
    }


    
    }
    {

      space[i] = token;
      i++;
      token = strtok(NULL, " ");




	} 
	 
		 
	} 
	 else if(strcmp(input,"exit")==0)
	 { printf(".....Exiting....");
		 break;}
	 
        
	
        free(input);
    }

    return 0;
}

