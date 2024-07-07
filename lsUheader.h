#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>
#include<dirent.h>
void lsU(){
        DIR *dir;
        struct dirent *entry;
        struct stat name;
        dir = opendir(".");
    

        if(dir == NULL){
                printf("couold not open the directory");
                return 1;
        }
        while ((entry=readdir(dir)) != NULL){
                if(entry->d_name[0] != '.'){
                printf("%s  ",entry->d_name);
        }}
        puts("");
        closedir(dir);
        
}

