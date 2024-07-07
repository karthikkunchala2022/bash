#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define BUFFER_SIZE 512

void cp(int argc, char * argv[]) {
    // Check if correct number of arguments provided
    if (argc != 3) {
        printf("Usage: cp <source_file> <destination_file>\n");
        exit(EXIT_FAILURE);
    }

    // Open source file for reading
    FILE *source_file = fopen(argv[1], "rb");
    if (source_file == NULL) {
        printf("Error: could not open file %s\n",argv[1]);
        exit(EXIT_FAILURE);
    }

    // Open destination file for writing
    FILE *destination_file = fopen(argv[2], "wb");
    if (destination_file == NULL) {
        printf("Error: could not open file %s\n",argv[2]);
        fclose(source_file);
        exit(EXIT_FAILURE);
    }

    // Copy file contents
    char buffer[BUFFER_SIZE];
    size_t bytes_read;
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_file)) > 0) {
        fwrite(buffer, 1, bytes_read, destination_file);
    }

    // Close files
    fclose(source_file);
    fclose(destination_file);

   
}

