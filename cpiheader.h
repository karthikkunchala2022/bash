void cpi(int argc, char *argv[]) {
    FILE *source_file, *target_file;
    char ch;
    int overwrite = 0;

    if (argc != 3) {
        printf("Usage: cp [-i] source_file target_file\n");
        exit(1);
    }

    if (strcmp(argv[1], "-i") == 0) {
        overwrite = 1;
        source_file = fopen(argv[2], "r");
        if (source_file == NULL) {
            printf("Error opening source file.\n");
            exit(1);
        }
        target_file = fopen(argv[3], "w");
        if (target_file == NULL) {
            printf("Error opening target file.\n");
            fclose(source_file);
            exit(1);
        }
    } else {
        source_file = fopen(argv[1], "r");
        if (source_file == NULL) {
            printf("Error opening source file.\n");
            exit(1);
        }
        target_file = fopen(argv[2], "w");
        if (target_file == NULL) {
            printf("Error opening target file.\n");
            fclose(source_file);
            exit(1);
        }
    }
if (overwrite == 0) {
        char response;
        target_file = fopen(argv[2], "r");
        if (target_file != NULL) {
            printf("cp: overwrite '%s'? (y/n) ", argv[2]);
            scanf(" %c", &response);
            if (response == 'n' || response == 'N') {
                printf("cp: '%s' not overwritten.\n", argv[2]);
                fclose(source_file);
                fclose(target_file);
                exit(0);
            }
        }
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, target_file);
    }

    printf("File copied successfully.\n");

    fclose(source_file);
    fclose(target_file);

    
}

