#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include<string.h>
void cpl(int argc, char *argv[]) {
    FILE *source_file;
    int result;

    if (argc < 3 || argc > 4 || (argc == 4 && strcmp(argv[1], "-l") != 0)) {
        printf("Usage: cp [-l] source_file target_file\n");
        exit(1);
    }

    if (argc == 4) {
        result = link(argv[2], argv[3]);
    } else {
        result = link(argv[1], argv[2]);
    }

    if (result != 0) {
        printf("Error creating hard link: %s\n", strerror(errno));
        exit(1);
    }

    printf("Hard link created successfully.\n");

   
}

