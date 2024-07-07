void mv(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: mv <oldfile> <newfile>\n");
        exit(1);
    }

    int fd1, fd2, n;
    char buffer[1024];

    fd1 = open(argv[1], O_RDONLY);
    if(fd1 == -1) {
        perror("open");
        exit(1);
    }

    fd2 = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if(fd2 == -1) {
        perror("open");
        exit(1);
    }

    while((n = read(fd1, buffer, sizeof(buffer))) > 0) {
        if(write(fd2, buffer, n) != n) {
            perror("write");
            exit(1);
        }
    }

    if(n == -1) {
        perror("read");
        exit(1);
    }

    if(close(fd1) == -1) {
        perror("close");
        exit(1);
    }

    if(close(fd2) == -1) {
        perror("close");
        exit(1);
    }

    if(unlink(argv[1]) == -1) {
        perror("unlink");
        exit(1);
    }

}

