void mvl(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: mv -l <oldfile> <newfile>\n");
        exit(1);
    }

    if(link(argv[1], argv[2]) == -1) {
        perror("link");
        exit(1);
    }

    if(unlink(argv[1]) == -1) {
        perror("unlink");
        exit(1);
    }

    }
