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

int compare_sizes(const void *a, const void *b);

void ls(void) {
    DIR *dir;
    struct dirent *entry;
    struct stat statbuf;
    char **filenames;
    int nfiles = 0;
    int i, j;

    // Open the current directory
    dir = opendir(".");
    if (dir == NULL) {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    // Count the number of files in the directory
    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &statbuf) == 0) {
            if (S_ISREG(statbuf.st_mode)) {
                nfiles++;
            }
        }
    }

    // Allocate memory for the filename array
    filenames = (char **) malloc(nfiles * sizeof(char *));
    if (filenames == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Fill the filename array with the names of the regular files in the directory
    rewinddir(dir);
    i = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (stat(entry->d_name, &statbuf) == 0) {
            if (S_ISREG(statbuf.st_mode)) {
                filenames[i] = strdup(entry->d_name);
                i++;
            }
   }
    }

    // Print the sorted filename array
    for (i = 0; i < nfiles; i++) {
        printf("%s   ", filenames[i]);
        free(filenames[i]);
    }

    // Free the filename array and close the directory
    free(filenames);
    closedir(dir);
 puts("");
    
}

int compare_sizes(const void *a, const void *b) {
    struct stat *statbuf1 = (struct stat *) a;
    struct stat *statbuf2 = (struct stat *) b;
    if (statbuf1->st_size < statbuf2->st_size) {
        return -1;
    } else if (statbuf1->st_size > statbuf2->st_size) {
        return 1;
    } else {
      return 0;
    }
}
                                                                                                                                                       

