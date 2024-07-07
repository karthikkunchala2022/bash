#define BUFFER_SIZE 512

void cpv(int argc, char *argv[]) {
    FILE *source_file, *target_file;
    char ch;

    if (argc != 3) {
        printf("Usage: cp source_file target_file\n");
        exit(1);
    }

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

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, target_file);
    }

    printf("'%s' has been copied to '%s' successfully.\n", argv[1], argv[2]);

    fclose(source_file);
    fclose(target_file);

   
}
