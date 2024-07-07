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
#define MAX_FILES 1000
#define MAX_FILENAME_LEN 256
void  ls() {
    DIR *dir;
    struct dirent *ent;
    char filenames[MAX_FILES][MAX_FILENAME_LEN];
    int i, j, n = 0;
    char temp[MAX_FILENAME_LEN];

    dir = opendir(".");
    if (dir == NULL) {
        perror("Failed to open directory");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL && n < MAX_FILES) {
       if (ent->d_name[0] != '.') {
            strncpy(filenames[n++], ent->d_name, MAX_FILENAME_LEN);
        }
    }

    closedir(dir);

    // Bubble sort filenames
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (strcmp(filenames[j], filenames[j + 1]) > 0) {
                strncpy(temp, filenames[j], MAX_FILENAME_LEN);
                strncpy(filenames[j], filenames[j + 1], MAX_FILENAME_LEN);
                strncpy(filenames[j + 1], temp, MAX_FILENAME_LEN);
            }
        }
    }

    // Print sorted filenames
    for (i = 0; i < n; i++) {
        printf("%s    ", filenames[i]);
	
    }
 puts("");
    
}

