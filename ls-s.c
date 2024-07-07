#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>

void lss(int argc, char *argv[]) {
	
    DIR *dir;
    struct dirent *entry;
    struct stat filestat;
    int total_blocks = 0;

    if(argc != 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        exit(1);
    }

    if((dir = opendir(argv[1])) == NULL) {
        perror("opendir");
        exit(1);
    }

    printf("total ");
    while((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        if(stat(path, &filestat) == -1) {
            perror("stat");
            exit(1);
        }

        total_blocks += filestat.st_blocks;
    }

    printf("%d\n", (total_blocks/2)); // Divide by 2 to convert from 512-byte blocks to 1kB blocks

    rewinddir(dir);

    while((entry = readdir(dir)) != NULL) {
        char path[1024];
        snprintf(path, sizeof(path), "%s/%s", argv[1], entry->d_name);

        if(stat(path, &filestat) == -1) {
            perror("stat");
            exit(1);
        }

        printf("%ld %s\n", (filestat.st_blocks/2), entry->d_name);
    }

    closedir(dir);

    
}

