#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int grep(int argc, char *argv[]) {
    if (argc != 3 && argc != 4 && argc != 5 && argc != 6) {
        printf("Usage: %s [-i] [-H] [-m num_matches] [-n] search_string file_path\n", argv[0]);
        return 1;
    }

    char *search_string = argv[1];
    char *file_path = argv[2];
    int case_insensitive = 0;
    int print_filename = 0;
    int max_matches = -1;
    int print_line_numbers = 0;

    if (argc >= 4 && strcmp(argv[1], "-i") == 0) {
        case_insensitive = 1;
        search_string = argv[2];
        file_path = argv[3];
    }

    if (argc >= 4 && strcmp(argv[1], "-H") == 0) {
        print_filename = 1;
        search_string = argv[2];
        file_path = argv[3];
    }

    if (argc >= 4 && strcmp(argv[1], "-n") == 0) {
        print_line_numbers = 1;
        search_string = argv[2];
        file_path = argv[3];
    }

    if (argc == 5 && strcmp(argv[1], "-m") == 0) {
        max_matches = atoi(argv[2]);
        search_string = argv[3];
        file_path = argv[4];
    }

    if (argc == 5 && strcmp(argv[2], "-i") == 0) {
        case_insensitive = 1;
        search_string = argv[3];
        file_path = argv[4];
    }

    if (argc == 5 && strcmp(argv[2], "-H") == 0) {
        print_filename = 1;
        search_string = argv[3];
        file_path = argv[4];
    }

    if (argc == 5 && strcmp(argv[2], "-n") == 0) {
        print_line_numbers = 1;
        search_string = argv[3];
        file_path = argv[4];
    }

    if (argc == 6 && strcmp(argv[2], "-m") == 0) {
        max_matches = atoi(argv[3]);
        search_string = argv[4];
        file_path = argv[5];
    }

    if (argc == 6 && strcmp(argv[2], "-i") == 0) {
        case_insensitive = 1;
        search_string = argv[3];
        file_path = argv[4];
    }

    if (argc == 6 && strcmp(argv[2], "-H") == 0) {
        print_filename = 1;
        search_string = argv[3];
        file_path = argv[4];
    }

    if (argc == 6 && strcmp(argv[2], "-n") == 0) {
        print_line_numbers = 1;
        search_string = argv[3];
        file_path = argv[4];
    }

    FILE *file = fopen(file_path, "r");
    if (!file) {
        printf("Error opening file: %s\n", file_path);
        return 1;
    }

    char *line = NULL;
    size_t line_len = 0;
    ssize_t read;
    int num_matches = 0;
    int line_number = 0;

    while ((read = getline(&line, &line_len, file)) != -1) {
        line_number++;

        char *found;
        if (case_insensitive) {
            found = strcasestr(line, search_string);
        } else {
            found = strstr(line, search_string);
        }

        if (found) {
            if (print_filename) {
                printf("%s:", file_path);
            }

            if (print_line_numbers) {
                printf("%d:", line_number);
            }

            fwrite(line, read, 1, stdout);
            num_matches++;

            if (max_matches != -1 && num_matches >= max_matches) {
                break;
            }
        }
    }

    if (num_matches == 0) {
        printf("No matches found.\n");
    }

    free(line);
    fclose(file);

    return 0;
}

