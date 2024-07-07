void cpf(int argc, char *argv[]) {
    FILE *source_file, *target_file;
    char ch;
    int force_flag = 0;

    if (argc < 3 || argc > 4) {
        printf("Usage: cp [-f] source_file target_file\n");
        exit(1);
    }

    if (argc == 4 && strcmp(argv[1], "-f") == 0) {
        force_flag = 1;
    }

    source_file = fopen(argv[force_flag + 1], "rb");
    if (source_file == NULL) {
        printf("Error opening source file.\n");
        exit(1);
    }

    target_file = fopen(argv[force_flag + 2], force_flag ? "wb" : "wxb");
    if (target_file == NULL) {
        printf("Error opening target file.\n");
        fclose(source_file);
        exit(1);
    }

    while ((ch = fgetc(source_file)) != EOF) {
        fputc(ch, target_file);
    }

    printf("File copied successfully.\n");

    fclose(source_file);
    fclose(target_file);

    
}

